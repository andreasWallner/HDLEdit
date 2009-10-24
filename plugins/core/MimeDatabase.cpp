#include "MimeDatabase.h"
#include "IEditor.h"
#include "dialogs/DefaultEditorDialog.h"

#include <stdexcept>

// TODO save preferred editor

MimeDatabase::MimeDatabase()
{
}

void MimeDatabase::registerEditor( const QString& mimeType, IEditor* editor)
{
	const QList<MimeEntry>& entrys = m_mimetypes.values(mimeType);
	foreach( const MimeEntry& entry, entrys)
	{
		if( entry.editor == editor)
			throw std::logic_error("MimeDatabase::registerEditor: tried to register same mime/editor tuple twice");
	}

	MimeEntry newEntry;
	newEntry.preferred = false;
	newEntry.name = editor->name();
	newEntry.editor = editor;

	m_mimetypes.insert( mimeType, newEntry);
}

IEditor* MimeDatabase::getEditor( const QString& mimeType)
{
	const QList<MimeEntry>& entrys = m_mimetypes.values(mimeType);

	foreach( const MimeEntry& entry, entrys)
	{
		if( entry.preferred == true)
			return entry.editor;
	}
	return 0;
}

IEditor* MimeDatabase::getEditorInteractive( const QString& mimeType, bool useDefault, Reason& reason)
{
	const QList<MimeEntry>& entrys = m_mimetypes.values(mimeType);

	if( entrys.size() == 0)
	{
		reason = NotFound;
		return 0;
	}

	if(useDefault)
	{
		foreach( const MimeEntry& entry, entrys)
		{
			if( entry.preferred == true)
				return entry.editor;
		}
	}

	DefaultEditorDialog dialog;
	dialog.setMimeType(mimeType);

	foreach( const MimeEntry& entry, entrys)
	{
		dialog.addEditor(entry.name);
	}

	int ret = dialog.exec();
	if( ret == QDialog::Accepted)
	{
		const QString& name = dialog.getEditor();
		foreach( const MimeEntry& entry, entrys)
		{
			if( entry.name == name)
				return entry.editor;
		}
	}

	reason = UserCancelled;
	return 0;
}
