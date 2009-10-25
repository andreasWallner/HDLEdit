#ifndef core_MimeDatabase_h_
#define core_MimeDatabase_h_

#include "PluginGlobal.h"

#include <QMultiMap>
#include <QString>

class IEditor;

class MimeDatabase
{
public:
	enum Reason
	{
		NotFound,
		UserCancelled,
		OK
	};

	MimeDatabase();

	void registerEditor( const QString& mimeType, IEditor* editor);
	IEditor* getEditor( const QString& mimeType);
	IEditor* getEditorInteractive( const QString& mimeType, bool useDefault, Reason& reason);

private:
	struct MimeEntry
	{
		bool preferred;
		QString name;
		IEditor* editor;
	};

	QMultiMap< QString, MimeEntry> m_mimetypes;
};

#endif // core_MimeDatabase_h_
