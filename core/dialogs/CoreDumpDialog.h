#ifndef CoreDumpDialog_h_
#define CoreDumpDialog_h_

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

#endif // CoreDumpDialog_h_
