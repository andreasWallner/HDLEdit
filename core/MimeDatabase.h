#ifndef core_MimeDatabase_h_
#define core_MimeDatabase_h_

#include "export.h"

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
		Ok
	};

	MimeDatabase();
	~MimeDatabase();

	void registerEditor( IEditor* editor, const QString& mimeType);
	bool removeEditor( const IEditor* editor);

	IEditor* getEditor( const QString& mimeType) const;
	IEditor* getEditorInteractive( const QString& mimeType, Reason& reason, bool useDefault = true);

private:
	struct MimeEntry
	{
		bool preferred;
		IEditor* editor;
	};

	QMultiMap<QString, MimeEntry> m_mimetypes;
};

#endif // core_MimeDatabase_h_
