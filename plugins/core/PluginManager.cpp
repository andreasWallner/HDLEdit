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
}

int PluginManager::initialize()
{
	QStringList failed;
	loadLibraries();

	failed = checkBaseServices();
	if( failed.size())
	{
		CoreDumpDialog dump;
		dump.setLabel(tr("Failed loading base services"));

		QString msg;
		msg = "<b>" + tr("Missing services:") + "</b><br /><br />";
		foreach( QString str, failed)
			msg += str + "<br />";
		dump.setTextBox(msg);
		dump.exec();

		return 1;
	}

	failed = checkDependencies();
	if( failed.size())
	{
		CoreDumpDialog dump;
		dump.setLabel(tr("Program could not be started"));

		QString msg;
		msg = "<b>" + tr("Unsatisfied dependencies:") + "</b><br /><br />";
		foreach( QString str, failed)
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
	m_iconFactory = factory;
}

void PluginManager::registerMimeTypeManager( IMimeTypeManager* manager)
{

}

/*void PluginManager::registerLogger( ILogger* logger)
{

}*/

void PluginManager::registerSettingsEngine( ISettingsEngine* editor)
{

}

void PluginManager::registerProjectManager( IProjectManager* manager)
{

}

void PluginManager::loadLibraries()
{
	QDir pluginDir(qApp->applicationDirPath());
	pluginDir.cd("plugins");

	foreach( QString fileName, pluginDir.entryList(QDir::Files))
	{
		QPluginLoader pluginLoader(pluginDir.absoluteFilePath(fileName));
		QObject *plugin = pluginLoader.instance();
		if (plugin)
		{
			IPlugin* casted = qobject_cast<IPlugin *>(plugin);
			if(casted) m_loadedPlugins << casted;
		}
	}
}

QStringList PluginManager::checkBaseServices()
{
	QStringList needed;
	for( int i = 0; i < baseServicesCount; ++i)
		needed << QString(baseServices[i]);

	QStringList provided;
	foreach( IPlugin* plugin, m_loadedPlugins)
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
	foreach( IPlugin* plugin, m_loadedPlugins)
		provided << plugin->provides();

	QStringList missing;
	foreach( IPlugin* plugin, m_loadedPlugins)
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
