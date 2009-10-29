#include "PluginManager.h"
#include "IPlugin.h"
#include "dialogs/CoreDumpDialog.h"

#include <QApplication>
#include <QPluginLoader>
#include <QLibrary>
#include <QDir>

#include <QtDebug>

// TODO get rid of count
static const int baseServicesCount = 2;
static const char* baseServices[] = { "base/settingsengine",
                                      "base/projectmanager" };

PluginManager::PluginManager()
{
}

PluginManager::~PluginManager()
{
	foreach( IPlugin* plugin, m_loadedPlugins)
		delete plugin;

	foreach( QPluginLoader* loader, m_pluginLoaders)
		delete loader;
}

int PluginManager::initialize()
{
	QStringList failed;
	loadLibraries();

	failed = checkBaseServices();
	if( failed.size())
	{
		CoreDumpDialog dump;
		dump.setLabel( tr("Failed loading base services"));

		QString msg;
		msg = "<b>" + tr("Missing services:") + "</b><br /><br />";
		foreach( const QString& str, failed)
			msg += str + "<br />";
		dump.setTextBox(msg);
		dump.exec();

		return 1;
	}

	failed = checkDependencies();
	if( failed.size())
	{
		CoreDumpDialog dump;
		dump.setLabel( tr("Program could not be started"));

		QString msg;
		msg = "<b>" + tr("Unsatisfied dependencies:") + "</b><br /><br />";
		foreach( const QString& str, failed)
			msg += str + "<br />";
		dump.setTextBox(msg);
		dump.exec();

		return 2;
	}

	correctLoadOrder();
	registerPlugins();
	return 0;
}

void PluginManager::registerIconFactory( IIconFactory* factory)
{
	p_iconFactory = factory;
}

void PluginManager::registerMimeTypeManager( IMimeTypeManager* manager)
{
	p_mimeTypeManager = manager;
}

/*void PluginManager::registerLogger( ILogger* logger)
{

}*/

void PluginManager::registerSettingsEngine( ISettingsEngine* engine)
{
	p_settingsEngine = engine;
}

void PluginManager::registerProjectManager( IProjectManager* manager)
{
	p_projectManager = manager;
}

IIconFactory* PluginManager::getIconFactory()
{
	return p_iconFactory;
}

IMimeTypeManager* PluginManager::getMimeTypeManager()
{
	return p_mimeTypeManager;
}

ISettingsEngine* PluginManager::getSettingsEngine()
{
	return p_settingsEngine;
}

IProjectManager* PluginManager::getProjectManager()
{
	return p_projectManager;
}

void PluginManager::loadLibraries()
{
	QDir pluginDir( qApp->applicationDirPath());
	pluginDir.cd("plugins");
	const QStringList& pluginList = pluginDir.entryList(QDir::Files | QDir::Executable | QDir::NoSymLinks);

	foreach( const QString& fileName, pluginList)
	{
		QPluginLoader* loader = new QPluginLoader( pluginDir.absoluteFilePath(fileName));
		QObject* plugin = loader->instance();

		if(plugin)
		{
			m_pluginLoaders << loader;
			IPlugin* casted = qobject_cast<IPlugin*>(plugin);
			if(casted) m_loadedPlugins << casted;
			else
			{
				delete plugin;
				qDebug() << "error loading doing qobject_cast: " << fileName;
			}
		}
		else
		{
			delete loader;
			qDebug() << "error loading plugin from: " << fileName;
		}
	}
}

QStringList PluginManager::checkBaseServices()
{
	QStringList needed;
	for( int i = 0; i < baseServicesCount; ++i)
		needed << QString(baseServices[i]);

	QStringList provided;
	foreach( const IPlugin* plugin, m_loadedPlugins)
		provided << plugin->provides();

	QStringList notProvided;
	foreach( const QString& dep, needed)
	{
		if( provided.indexOf(dep) == -1)
			notProvided << dep;
	}
	return notProvided;
}

QStringList PluginManager::checkDependencies()
{
	QStringList provided;
	foreach( const IPlugin* plugin, m_loadedPlugins)
		provided << plugin->provides();

	QStringList missing;
	foreach( const IPlugin* plugin, m_loadedPlugins)
	{
		QStringList needs = plugin->depends();
		foreach( const QString& need, needs)
		{
			if( provided.indexOf(need) == -1)
				missing << need;
		}
	}
	return missing;
}

void PluginManager::correctLoadOrder()
{
	bool madeChanges;

	do {
		madeChanges = false;

		for( int i = 0; i < m_loadedPlugins.size(); ++i)
		{
			const QStringList& needed = m_loadedPlugins.at(i)->depends();
			if( needed.size() == 0) continue;

			QStringList covered;
			for( int j = 0; j < m_loadedPlugins.size(); ++j)
			{
				// it is needed and not covered
				if( needed.indexOf( m_loadedPlugins.at(j)->provides()) != -1
				 && covered.indexOf( m_loadedPlugins.at(j)->provides()) == -1)
					covered << m_loadedPlugins.at(j)->provides();

				if( covered.size() == needed.size())
				{
					if( i < j)
					{
						m_loadedPlugins.move( i, j);
						madeChanges = true;
					}
					break;
				}
			}
		}
	} while(madeChanges);
}

void PluginManager::registerPlugins()
{
	foreach( IPlugin* plugin, m_loadedPlugins)
		plugin->registerPlugin(this);
}
