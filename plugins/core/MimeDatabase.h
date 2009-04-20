#ifndef MIMEDATABASE_H
#define MIMEDATABASE_H

#include "PluginGlobal.h"

class QString;
class IEditor;

class MimeDatabase
{
public:
	MimeDatabase();

	void registerEditor( QString mimeType, IEditor* editor);
	IEditor* getEditor( QString mimeType);
};

#endif // MIMEDATABASE_H
