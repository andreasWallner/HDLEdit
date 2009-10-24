#include "VHDLEditor.h"

#include <QString>
#include <QStringList>

VHDLEditor::VHDLEditor()
{
}

QString VHDLEditor::name() const
{
	return "VHDL Text Editor";
}

QString VHDLEditor::description() const
{
	return "I am a VHDL test editor.";
}

QString VHDLEditor::version() const
{
	return "0.1";
}

QString VHDLEditor::provides() const
{
	return "editor/vhdl-text";
}

QStringList VHDLEditor::depends() const
{
	QStringList list;
	list << "base/projectmanager";
	return list;
}

void VHDLEditor::registerPlugin( PluginManager* manager)
{
}

Q_EXPORT_PLUGIN2(VHDLEditor, VHDLEditor);
