#include "LogWindow.h"
#include "ui_LogWindow.h"

#include <QtDebug>

LogWindow::LogWindow(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::LogWindow)
{
    m_ui->setupUi(this);
}

LogWindow::~LogWindow()
{
    delete m_ui;
}

void LogWindow::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void LogWindow::addLogContent( QString window, QString message)
{
	qDebug() << window << ": " << message;
}

void LogWindow::addLogLine( QString window, QString message)
{
	qDebug() << window << ": " << message;
}
