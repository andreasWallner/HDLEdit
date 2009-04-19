#include "CoreDumpDialog.h"
#include "ui_CoreDumpDialog.h"

CoreDumpDialog::CoreDumpDialog(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::CoreDumpDialog)
{
    m_ui->setupUi(this);
}

CoreDumpDialog::~CoreDumpDialog()
{
    delete m_ui;
}

void CoreDumpDialog::setLabel( QString text)
{
	m_ui->label->setText(text);
}

void CoreDumpDialog::setTextBox( QString text)
{
	m_ui->textBrowser->setText(text);
}

void CoreDumpDialog::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
