#include "AppSettings.h"

#include <QString>
#include <QStringList>
#include <QtPlugin>

AppSettings::AppSettings()
{
}

AppSettings::~AppSettings()
{
}

QString AppSettings::name() const
{
	return "AppSettings";
}

QString AppSettings::version() const
{
	return "1.0.0";
}

QString AppSettings::provides() const
{
	return "base/settingseditor";
}

QStringList AppSettings::depends() const
{
	QStringList list;
	list << "base/iconmanager";
	return list;
}

void AppSettings::registerPlugin( PluginManager* manager)
{
}

Q_EXPORT_PLUGIN2(AppSettings, AppSettings);
