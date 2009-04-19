#ifndef PluginManager_h_
#define PluginManager_h_

#include "PluginGlobal.h"

#include <QObject>

class IPlugin;
class IIconFactory;
class IMimeTypeManager;
class ILogger;
class ISettingsEditor;
class IProjectManager;

// TODO check for circular deps

class /*CORE_EXPORT*/ PluginManager : public QObject
{
public:
	PluginManager();
	~PluginManager();

	int initialize();

	void registerIconFactory( IIconFactory* factory);
	void registerMimeTypeManager( IMimeTypeManager* manager);
	void registerLogger( ILogger* logger);
	void registerSettingsEditor( ISettingsEditor* editor);
	void registerProjectManager( IProjectManager* manager);

	IIconFactory* getIconFactory();
	IMimeTypeManager* getMimeTypeManager();
	ILogger* getLogger();
	ISettingsEditor* getSettingsEditor();
	IProjectManager* getProjectManager();
protected:
	void loadLibraries();
	QStringList checkBaseServices();
	QStringList checkDependencies();
	void correctLoadOrder();
	void registerPlugins();

	QList<IPlugin*> m_loadedPlugins;

	IIconFactory* m_iconFactory;
	IMimeTypeManager* m_mimeTypeManager;
	ILogger* m_logger;
	ISettingsEditor* m_settingsEditor;
	IProjectManager* m_projectManager;
};

#endif // PluginManager_h_
