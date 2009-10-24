#include "DefaultEditorDialog.h"
#include "ui_DefaultEditorDialog.h"

DefaultEditorDialog::DefaultEditorDialog( QWidget* parent)
: QDialog(parent)
, p_ui(new Ui::DefaultEditorDialog)
{
	p_ui->setupUi(this);
}

DefaultEditorDialog::~DefaultEditorDialog()
{
	delete p_ui;
}

void DefaultEditorDialog::setMimeType( const QString& name)
{
	const QString& text = tr("Please choose your default Editor for %0 Files").arg(name);
	p_ui->introTextLabel->setText(text);
}

void DefaultEditorDialog::addEditor( const QString& name)
{
	p_ui->editorCombo->addItem(name);
}

QString DefaultEditorDialog::getEditor() const
{
	return p_ui->editorCombo->currentText();
}

void DefaultEditorDialog::changeEvent( QEvent* e)
{
	switch(e->type())
	{
	case QEvent::LanguageChange:
		p_ui->retranslateUi(this);
		break;
	default:
		break;
	}
}
