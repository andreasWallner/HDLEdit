#ifndef IPlugin_h_
#define IPLugin_h_

#include <QtPlugin>
#include "PluginGlobal.h"

class PluginManager;

class CORE_EXPORT IPlugin
{
public:
	virtual ~IPlugin();

	virtual QString name() const = 0;
	virtual QString description() const = 0;
	virtual QString version() const = 0;
	virtual QString provides() const = 0;
	virtual QStringList depends() const = 0;
	virtual void registerPlugin( PluginManager* manager) = 0;
};

Q_DECLARE_INTERFACE( IPlugin, "com.HDLEdit.plugin/1.0");

#endif // IPLugin_h_
