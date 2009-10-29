#ifndef PluginManager_h_
#define PluginManager_h_

#include "../export.h"
#include <QObject>

class Logger;
class IPlugin;
class IIconFactory;
class IMimeTypeManager;
class ISettingsEngine;
class IProjectManager;
class QPluginLoader;

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
	IIconFactory* getIconFactory();
	IMimeTypeManager* getMimeTypeManager();
	ISettingsEngine* getSettingsEngine();
	IProjectManager* getProjectManager();

private:
	void loadLibraries();
	QStringList checkBaseServices();
	QStringList checkDependencies();
	void correctLoadOrder();
	void registerPlugins();

	QList<QPluginLoader*> m_pluginLoaders;
	QList<IPlugin*> m_loadedPlugins;

	IIconFactory* p_iconFactory;
	IMimeTypeManager* p_mimeTypeManager;
	//Logger* p_logger;
	ISettingsEngine* p_settingsEngine;
	IProjectManager* p_projectManager;
};

#endif // PluginManager_h_
