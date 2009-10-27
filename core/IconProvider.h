#ifndef core_IconProvider_h_
#define core_IconProvider_h_

#include "export.h"

class QIcon;

class CORE_EXPORT IconProvider
{
public:
	IconProvider();
	~IconProvider();

	QIcon getIcon( const QString& identifier);
};

#endif // core_IconProvider_h_
