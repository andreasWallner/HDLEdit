#ifndef ICONPROVIDER_H
#define ICONPROVIDER_H

#include "PluginGlobal.h"
#include <QObject>

class QIcon;

class CORE_EXPORT IconProvider : public QObject
{
public:
	IconProvider();
	QIcon getIcon( const QString& identifier);
};

#endif // ICONPROVIDER_H
