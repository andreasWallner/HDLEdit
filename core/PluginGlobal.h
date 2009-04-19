#ifndef PluginGlobal_h_
#define PluginGlobal_h_

#include <QtGlobal>

#ifdef LIB_BUILD
	#ifdef Q_OS_WIN32
		#define CORE_EXPORT __declspec(dllexport)
	#elif defined(QT_VISIBILITY_AVAILABLE)
		#define CORE_EXPORT __attribute__((visibility("default")))
	#endif
#endif // LIB_BUILD

#ifndef LIB_BUILD
	#ifdef Q_OS_WIN32
		#define CORE_EXPORT __declspec(dllimport)
	#else
		#define CORE_EXPORT
	#endif
#endif // LIB_BUILD

#endif // PluginGlobal_h_
