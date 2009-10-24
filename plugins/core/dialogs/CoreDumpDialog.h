#ifndef COREDUMPDIALOG_H
#define COREDUMPDIALOG_H

#include <QtGui/QDialog>

namespace Ui { class CoreDumpDialog; }

class CoreDumpDialog : public QDialog
{
    Q_OBJECT
    Q_DISABLE_COPY(CoreDumpDialog)

public:
	CoreDumpDialog( QWidget* parent = 0);
	~CoreDumpDialog();

	void setLabel( const QString& text);
	void setTextBox( const QString& text);

private slots:
	void changeEvent( QEvent* e);

private:
    Ui::CoreDumpDialog* p_ui;
};

#endif // COREDUMPDIALOG_H
