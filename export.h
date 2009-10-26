#ifndef export_h_
#define export_h_

#include <QtCore/qglobal.h>

#if defined(CORE_LIBRARY)
	#define CORE_EXPORT Q_DECL_EXPORT
#else
	#define CORE_EXPORT Q_DECL_IMPORT
#endif

#endif // export_h_
