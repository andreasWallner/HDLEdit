#ifndef ISettingsEngine_h_
#define ISettingsEngine_h_

#include "IPlugin.h"

//! SettingsEngines load/safe settings
class CORE_EXPORT ISettingsEngine : public IPlugin
{
public:
	//! Level of the setting to read/write
	enum SettingLevel
	{
		DefaultLevel = 0,
		ApplicationLevel = 10,
		UserLevel = 20,
		ProjectLevel = 30
	};

	virtual ~ISettingsEngine();

	//! removes a setting from the specified level
	/*!
	 * When the setting is removed the setting from the level below
	 * "shines through"
	 * remove is not allowed to change settings on the default level.
	 */
	virtual void remove( SettingLevel level, const QString& key) = 0;

	//!
	virtual void setValue( SettingLevel level, const QString& key, const QVariant& value) = 0;

	//!
	virtual QVariant getValue( SettingLevel level, const QString& key) const = 0;

	//!
	virtual QVariant getValue( const QString& key) const = 0;

	//!
	virtual bool isSet( SettingLevel level, const QString& key) const = 0;
};

Q_DECLARE_INTERFACE( ISettingsEngine, "com.HDLEdit.SettingsEngine/1.0");

#endif // ISettingsEngine_h_
