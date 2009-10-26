#ifndef QSettingsEngine_h_
#define QSettingsEngine_h_

#include <QObject>
#include "core/ISettingsEngine.h"

class QSettingsEngine : public QObject, public ISettingsEngine
{
	Q_OBJECT
	Q_INTERFACES(IPlugin ISettingsEngine)

public:
	QSettingsEngine();

	QString name() const;
	QString description() const;
	QString version() const;
	QString provides() const;
	QStringList depends() const;
	void registerPlugin( PluginManager* manager);

	void remove( SettingLevel level, const QString& key);
	void setValue( SettingLevel level, const QString& key, const QVariant& value);
	QVariant getValue( SettingLevel level, const QString& key) const;
	QVariant getValue( const QString& key) const;
	bool isSet( SettingLevel level, const QString& key) const;
};

#endif // QSettingsEngine_h_
