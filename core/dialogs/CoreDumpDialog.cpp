#include "CoreDumpDialog.h"
#include "ui_CoreDumpDialog.h"

CoreDumpDialog::CoreDumpDialog( QWidget* parent)
: QDialog(parent)
, p_ui(new Ui::CoreDumpDialog)
{
	p_ui->setupUi(this);
}

CoreDumpDialog::~CoreDumpDialog()
{
	delete p_ui;
}

void CoreDumpDialog::setLabel( const QString& text)
{
	p_ui->label->setText(text);
}

void CoreDumpDialog::setTextBox( const QString& text)
{
	p_ui->textBrowser->setText(text);
}

void CoreDumpDialog::changeEvent( QEvent* e)
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
