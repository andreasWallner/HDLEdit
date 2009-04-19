#include "IconCache.h"

#include "core/PluginManager.h"

#include <QString>
#include <QStringList>

IconCache::IconCache()
{
}

QString IconCache::name() const
{
	return "IconCache";
}

QString IconCache::version() const
{
	return "0.1";
}

QString IconCache::provides() const
{
	return "base/iconmanager";
}

QStringList IconCache::depends() const
{
	return QStringList();
}

void IconCache::registerPlugin( PluginManager* manager)
{
	manager->registerIconFactory(this);
}

Q_EXPORT_PLUGIN2(IconCache, IconCache);
