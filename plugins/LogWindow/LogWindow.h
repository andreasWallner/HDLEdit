#ifndef LogWindow_h_
#define LogWindow_h_

#include <QObject>
#include "core/ILogger.h"

class LogWindow : public QObject, public ILogger
{
	Q_OBJECT
	Q_INTERFACES(IPlugin ILogger)
public:
	LogWindow();

	virtual QString name() const;
	virtual QString version() const;
	virtual QString provides() const;
	virtual QStringList depends() const;
	virtual void registerPlugin( PluginManager* manager);
};

#endif // LogWindow_h_
