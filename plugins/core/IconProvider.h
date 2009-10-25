#ifndef core_IconProvider_h_
#define core_IconProvider_h_

#include "PluginGlobal.h"
#include <QObject>

class QIcon;

class CORE_EXPORT IconProvider : public QObject
{
public:
	IconProvider();
	QIcon getIcon( const QString& identifier);
};

#endif // core_IconProvider_h_
