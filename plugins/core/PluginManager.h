#ifndef PluginManager_h_
#define PluginManager_h_

#include "PluginGlobal.h"

#include <QObject>

class Logger;
class IPlugin;
class IIconFactory;
class IMimeTypeManager;
class ISettingsEditor;
class IProjectManager;

// TODO check for circular deps
// TODO intelligently seach plugin folder

class CORE_EXPORT PluginManager : public QObject
{
public:
	PluginManager();
	~PluginManager();

	int initialize();

	void registerIconFactory( IIconFactory* factory);
	void registerMimeTypeManager( IMimeTypeManager* manager);
	void registerSettingsEditor( ISettingsEditor* editor);
	void registerProjectManager( IProjectManager* manager);

	// static services
//	Logger* getLogger();

	// dynamic services
	IIconFactory* getIconFactory();
	IMimeTypeManager* getMimeTypeManager();
	ISettingsEditor* getSettingsEditor();
	IProjectManager* getProjectManager();

private:
	void loadLibraries();
	QStringList checkBaseServices();
	QStringList checkDependencies();
	void correctLoadOrder();
	void registerPlugins();

	QList<IPlugin*> m_loadedPlugins;

	IIconFactory* m_iconFactory;
	IMimeTypeManager* m_mimeTypeManager;
	//Logger* m_logger;
	ISettingsEditor* m_settingsEditor;
	IProjectManager* m_projectManager;
};

#endif // PluginManager_h_
