#ifndef ICONPROVIDER_H
#define ICONPROVIDER_H

#include "PluginGlobal.h"
#include <QObject.h>

class QIcon;

class CORE_EXPORT IconProvider : public QObject
{
public:
		IconProvider();
		const QIcon getIcon( QString identifier);
};

#endif // ICONPROVIDER_H
