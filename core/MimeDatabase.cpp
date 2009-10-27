#include "MimeDatabase.h"
#include "IEditor.h"
#include "dialogs/DefaultEditorDialog.h"

#include <stdexcept>

// TODO save preferred editor

MimeDatabase::MimeDatabase()
{
}

MimeDatabase::~MimeDatabase()
{
}

void MimeDatabase::registerEditor( IEditor* editor, const QString& mimeType)
{
	if(!editor)
		throw std::invalid_argument("MimeDatabase::registerEditor: tried to register NULL pointer as editor");

	const QList<MimeEntry>& entrys = m_mimetypes.values(mimeType);
	foreach( const MimeEntry& entry, entrys)
	{
		if( entry.editor == editor)
			throw std::logic_error("MimeDatabase::registerEditor: tried to register same mime/editor tuple twice");
	}

	MimeEntry newEntry;
	newEntry.preferred = false;
	newEntry.editor = editor;
	m_mimetypes.insert( mimeType, newEntry);
}

bool MimeDatabase::removeEditor( const IEditor* editor)
{
	bool found = false;
	QMultiMap<QString, MimeEntry>::iterator it, end;

	for( it = m_mimetypes.begin(), end = m_mimetypes.end(); it != end;)
	{
		if( it->editor != editor) ++it;
		else
		{
			m_mimetypes.erase(it++);
			found = true;
		}
	}
	return found;
}

IEditor* MimeDatabase::getEditor( const QString& mimeType) const
{
	const QList<MimeEntry>& entrys = m_mimetypes.values(mimeType);

	foreach( const MimeEntry& entry, entrys)
	{
		if( entry.preferred == true)
			return entry.editor;
	}
	return 0;
}

IEditor* MimeDatabase::getEditorInteractive( const QString& mimeType, Status& status, bool useDefault /* = true */)
{
	const QList<MimeEntry>& entrys = m_mimetypes.values(mimeType);

	if( entrys.size() == 0)
	{
		status = NotFound;
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
		dialog.addEditor( entry.editor->name());
	}

	int ret = dialog.exec();
	if( ret == QDialog::Accepted)
	{
		const QString& name = dialog.getEditor();
		foreach( const MimeEntry& entry, entrys)
		{
			if( entry.editor->name() == name)
			{
				status = Ok;
				return entry.editor;
			}
		}
	}

	status = UserCancelled;
	return 0;
}
