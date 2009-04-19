#ifndef AppSettings_h_
#define AppSettings_h_

#include <QObject>
#include "core/ISettingsEditor.h"

class AppSettings : public QObject, public ISettingsEditor
{
	Q_OBJECT
	Q_INTERFACES(IPlugin ISettingsEditor)
public:
	AppSettings();
	virtual ~AppSettings();

	virtual QString name() const;
	virtual QString version() const;
	virtual QString provides() const;
	virtual QStringList depends() const;
	virtual void registerPlugin( PluginManager* manager);
};

#endif // AppSettings_h_
