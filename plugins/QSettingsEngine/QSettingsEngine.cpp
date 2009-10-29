#include "QSettingsEngine.h"
#include "PluginManager.h"

#include <QString>
#include <QStringList>
#include <QSettings>

QSettingsEngine::QSettingsEngine()
{}

QSettingsEngine::~QSettingsEngine()
{}

QString QSettingsEngine::name() const
{
	return "QSettingsEngine";
}

QString QSettingsEngine::description() const
{
	return "I am a QSettingsEngine.";
}

QString QSettingsEngine::version() const
{
	return "0.1";
}

QString QSettingsEngine::provides() const
{
	return "base/settingsengine";
}

QStringList QSettingsEngine::depends() const
{
	QStringList list;
	//list << "";
	return list;
}

void QSettingsEngine::registerPlugin( PluginManager* manager)
{
	manager->registerSettingsEngine(this);
}

void QSettingsEngine::remove( SettingLevel level, const QString& key)
{
}

void QSettingsEngine::setValue( SettingLevel level, const QString& key, const QVariant& value)
{
}

QVariant QSettingsEngine::getValue( SettingLevel level, const QString& key) const
{
	return QVariant();
}

QVariant QSettingsEngine::getValue( const QString& key) const
{
	return QVariant();
}

bool QSettingsEngine::isSet( SettingLevel level, const QString& key) const
{
	return false;
}

Q_EXPORT_PLUGIN2(QSettingsEngine, QSettingsEngine);
