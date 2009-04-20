#ifndef LowWindow_h_
#define LowWindow_h_

#include <QtGui/QDialog>
#include "PluginGlobal.h"
#include <QString>
#include <QMap>

namespace Ui {
    class LogWindow;
}

class QTextEdit;

class CORE_EXPORT LogWindow : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(LogWindow)
public:
    explicit LogWindow(QWidget *parent = 0);
    virtual ~LogWindow();
public slots:
		void addLogContent( QString window, QString message);
		void addLogLine( QString window, QString message);
protected:
    virtual void changeEvent(QEvent *e);

private:
		QMap< QString, QTextEdit*> m_tabs;
    Ui::LogWindow *m_ui;
};

#endif // LowWindow_h_
