#ifndef ILogger_h_
#define ILogger_h_

#include "IPlugin.h"

class ILogger : public IPlugin
{
public:
	virtual ~ILogger() {}

};

Q_DECLARE_INTERFACE( ILogger, "com.HDLEdit.Logger/1.0");

#endif // ILogger_h_
