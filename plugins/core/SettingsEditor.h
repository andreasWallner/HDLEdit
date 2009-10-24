#ifndef SettingsEditor_h_
#define SettingsEditor_h_

#include "ISettingsEngine.h"
#include <QDialog>

//! displays a modal setting editor window
class SettingsEditor : public QDialog
{
public:
	SettingsEditor( QWidget* parent = 0);
	~SettingsEditor();

	void showEditor( ISettingsEngine::SettingLevel);
};

#endif // SettingsEditor_h_
