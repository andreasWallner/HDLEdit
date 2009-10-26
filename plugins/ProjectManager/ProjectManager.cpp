#include "ProjectManager.h"

#include <QString>
#include <QStringList>

ProjectManager::ProjectManager()
{
}

QString ProjectManager::name() const
{
	return "Project Manager";
}

QString ProjectManager::description() const
{
	return "I am a projectmanager.";
}

QString ProjectManager::version() const
{
	return "0.1";
}

QString ProjectManager::provides() const
{
	return "base/projectmanager";
}

QStringList ProjectManager::depends() const
{
	QStringList list;
	list << "base/settingsengine";
	return list;
}

void ProjectManager::registerPlugin( PluginManager* manager)
{
}

Q_EXPORT_PLUGIN2(ProjectManager, ProjectManager);
