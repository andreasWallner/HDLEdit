#ifndef core_IconProvider_h_
#define core_IconProvider_h_

#include "PluginGlobal.h"

class QIcon;

class CORE_EXPORT IconProvider
{
public:
	IconProvider();
	QIcon getIcon( const QString& identifier);
};

#endif // core_IconProvider_h_
