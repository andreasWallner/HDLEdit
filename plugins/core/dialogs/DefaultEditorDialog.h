#ifndef DEFAULTEDITORDIALOG_H
#define DEFAULTEDITORDIALOG_H

#include <QtGui/QDialog>

namespace Ui { class DefaultEditorDialog; }

class DefaultEditorDialog : public QDialog
{
	Q_OBJECT
	Q_DISABLE_COPY(DefaultEditorDialog)

public:
	DefaultEditorDialog( QWidget* parent = 0);
	~DefaultEditorDialog();

	void setMimeType( const QString& name);
	void addEditor( const QString& name);
	QString getEditor() const;

private slots:
	void changeEvent( QEvent* e);

private:
	Ui::DefaultEditorDialog* p_ui;
};

#endif // DEFAULTEDITORDIALOG_H
