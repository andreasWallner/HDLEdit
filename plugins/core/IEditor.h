#ifndef core_IEditor_h_
#define core_IEditor_h_

#include "IPlugin.h"

// TODO make them global
enum HDL // do those need fixed values? (minimize ABI changes?)
{
	VHDL = 0,
	Verilog = 1,
	NoHDL = 2
};

enum OpenMode
{
	ReadOnly,
	ReadWrite
};

/*

struct HDLInterface // hdl independent
{
	generics
	interface lanes
}

*/

class CORE_EXPORT IEditor : public IPlugin
{
public:
	virtual ~IEditor() {}

	virtual void showEditor( const QString& file, OpenMode mode = ReadWrite) = 0;

	// maybe file information class??

	//virtual QString getHDLInterface( HDL hdl); // not here -> write classes for the HDLs and give them the generic and Interface specifications 
	virtual bool wasFunctionalModified( const QString& oldFile, const QString& newFile) = 0;
	virtual HDL getHDL( const QString& file) = 0;
	//virtual HDLInterface getInterface( const QString& file);
	// hierarchy browsing functions?
	// makefile generation functions?
	// information to build intellisense database?

};

Q_DECLARE_INTERFACE( IEditor, "com.HDLEdit.Editor/1.0");

#endif // core_IEditor_h_
