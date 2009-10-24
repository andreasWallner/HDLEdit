#include "LogWindow.h"
#include "ui_LogWindow.h"

#include <QTextEdit>
#include <QtDebug>

LogWindow::LogWindow( QWidget* parent)
: QDialog(parent)
, p_ui(new Ui::LogWindow)
{
	p_ui->setupUi(this);
	clearAllTabs();
}

LogWindow::~LogWindow()
{
	delete p_ui;
}

void LogWindow::changeEvent( QEvent* e)
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

void LogWindow::addLogContent( const QString& window, const QString& message)
{
	QMap< QString, QTextEdit*>::iterator tab = m_tabs.find(window);
	if( tab == m_tabs.end())
	{
		QTextEdit* textEdit = new QTextEdit(this);
		m_tabs.insert( window, textEdit);
		p_ui->tabWidget->addTab( textEdit, window);
		tab = m_tabs.find(window);
	}

	(*tab)->append(message);
	qDebug() << window << ": " << message;
}

void LogWindow::addLogLine( const QString& window, const QString& message)
{
	addLogContent( window, message);
	addLogContent( window, "<br />");
	qDebug() << window << ": " << message;
}

void LogWindow::clearAllTabs()
{
	while(p_ui->tabWidget->count())
		p_ui->tabWidget->removeTab(0);
	m_tabs.clear();
	addLogContent("AUX", tr("cleared log content"));
}

void LogWindow::on_tabWidget_tabCloseRequested( int index)
{
	if( p_ui->tabWidget->tabText(index) != "AUX")
	{
		m_tabs.remove(p_ui->tabWidget->tabText(index));
		QWidget* widget = p_ui->tabWidget->widget(index);
		p_ui->tabWidget->removeTab(index);
		delete widget;
	}
}
