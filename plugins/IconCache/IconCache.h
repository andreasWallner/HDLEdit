#ifndef IconCache_h_
#define IconCache_h_

#include <QObject>
#include "core/IIconFactory.h"

class IconCache : public QObject, public IIconFactory
{
	Q_OBJECT
	Q_INTERFACES(IPlugin IIconFactory)
public:
	IconCache();

	virtual QString name() const;
	virtual QString version() const;
	virtual QString provides() const;
	virtual QStringList depends() const;
	virtual void registerPlugin( PluginManager* manager);
};

#endif // IconCache_h_
