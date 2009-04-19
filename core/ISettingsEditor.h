#ifndef ISettingsEditor_h_
#define ISettingsEditor_h_

#include "IPlugin.h"

class ISettingsEditor : public IPlugin
{
public:
	virtual ~ISettingsEditor() {}

};

Q_DECLARE_INTERFACE( ISettingsEditor, "com.HDLEdit.SettingsEditor/1.0");

#endif // ISettingsEditor_h_
