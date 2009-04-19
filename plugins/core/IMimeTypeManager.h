#ifndef IMimeTypeManager_h_
#define IMimeTypeManager_h_

#include "IPlugin.h"

class IMimeTypeManager : public IPlugin
{
public:
	virtual ~IMimeTypeManager() {}

};

Q_DECLARE_INTERFACE( IMimeTypeManager, "com.HDLEdit.MimeTypeManager/1.0");

#endif // IMimeTypeManager_h_
