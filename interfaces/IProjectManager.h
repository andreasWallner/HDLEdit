#ifndef IProjectManager_h_
#define IProjectManager_h_

#include "IPlugin.h"

class CORE_EXPORT IProjectManager : public IPlugin
{
public:
	virtual ~IProjectManager();

	// what do we have to do

	// manage projects
	//virtual void openProject( const QString& path);


	// we need:
	// - list of types of files we can create
	// - a way to tell an editor to create an empty file after a template

	// we provide:
	// - managed entities in project
	// - information for version tracker
	// - control of compilation / synthesis / simulation
	// - export / import (project creation) functionality
	// - manage workflows (combine task into workflows)
	// - manage working directory
	// - interface for metainformation

	// typical workflow
	// create new file
	//	-> call mimetypeDatabase -> get editor -> tell it to open new file (with template?)
	// open file
	//	-> call mimetypeDatabase -> get editor -> tell it to open existing file (with template?)
	// mark changed files
	//	slot: void fileChanged( const QString& filename);
	// start compilation / simulation
	//	-> GUI calls workflow / task -> workflow asks for working dir
	// start synthesis
	//	-> GUI calls workflow / task -> workflow asks for working dir
	// push checked results to whatever repo
	//	-> ?

	// big question
	// monolithic project file?

/*
	example workflow
	- generate VHDL code (e.g. RAM)
	- let modelsim simulater compile
	- simulate in modelsim

	private pseudo-variables, provided by PluginManager:
	p_settingsEngine;
	p_mimeDatabase;
	p_iconProvider;
*/
};

Q_DECLARE_INTERFACE( IProjectManager, "com.HDLEdit.ProjectManager/1.0");

#endif // IProjectManager_h_
