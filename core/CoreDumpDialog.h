#ifndef COREDUMPDIALOG_H
#define COREDUMPDIALOG_H

#include <QtGui/QDialog>

namespace Ui {
    class CoreDumpDialog;
}

class CoreDumpDialog : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(CoreDumpDialog)
public:
    explicit CoreDumpDialog(QWidget *parent = 0);
    virtual ~CoreDumpDialog();

		void setLabel( QString text);
		void setTextBox( QString text);
protected:
    virtual void changeEvent(QEvent *e);
private:
    Ui::CoreDumpDialog *m_ui;
};

#endif // COREDUMPDIALOG_H
