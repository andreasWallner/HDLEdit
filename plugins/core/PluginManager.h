#ifndef PluginManager_h_
#define PluginManager_h_

#include "PluginGlobal.h"

#include <QObject>

class Logger;
class IPlugin;
class IIconFactory;
class IMimeTypeManager;
class ISettingsEngine;
class IProjectManager;

// TODO check for circular deps
// TODO intelligently seach plugin folder

class CORE_EXPORT PluginManager : public QObject
{
public:
	PluginManager();
	~PluginManager();

	int initialize();

	void registerIconFactory( IIconFactory*);
	void registerMimeTypeManager( IMimeTypeManager*);
	void registerSettingsEngine( ISettingsEngine*);
	void registerProjectManager( IProjectManager*);

	// static services
//	Logger* getLogger();

	// dynamic services
	IIconFactory* getIconFactory() { return p_iconFactory; }
	IMimeTypeManager* getMimeTypeManager() { return p_mimeTypeManager; }
	ISettingsEngine* getSettingsEngine() { return p_settingsEngine; }
	IProjectManager* getProjectManager() { return p_projectManager; }

private:
	void loadLibraries();
	QStringList checkBaseServices();
	QStringList checkDependencies();
	void correctLoadOrder();
	void registerPlugins();

	QList<IPlugin*> m_loadedPlugins;

	IIconFactory* p_iconFactory;
	IMimeTypeManager* p_mimeTypeManager;
	//Logger* p_logger;
	ISettingsEngine* p_settingsEngine;
	IProjectManager* p_projectManager;
};

#endif // PluginManager_h_
