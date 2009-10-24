#ifndef LowWindow_h_
#define LowWindow_h_

#include "./../PluginGlobal.h"

#include <QtGui/QDialog>
#include <QString>
#include <QMap>

namespace Ui { class LogWindow; }

class QTextEdit;

class CORE_EXPORT LogWindow : public QDialog
{
	Q_OBJECT
	Q_DISABLE_COPY(LogWindow)

public:
	LogWindow( QWidget* parent = 0);
	~LogWindow();

public slots:
	void addLogContent( const QString& window, const QString& message);
	void addLogLine( const QString& window, const QString& message);
	void clearAllTabs();

private slots:
	void on_tabWidget_tabCloseRequested( int index);
	void changeEvent( QEvent* e);

private:
	QMap< QString, QTextEdit*> m_tabs;
	Ui::LogWindow* p_ui;
};

#endif // LowWindow_h_
