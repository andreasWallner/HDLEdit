#ifndef ISourceControl_h_
#define ISourceControl_h_

#include "IPlugin.h"

class CORE_EXPORT ISourceControl : public IPlugin
{
public:
	virtual ~ISourceControl();

};

Q_DECLARE_INTERFACE( ISourceControl, "com.HDLEdit.SourceControl/1.0");

#endif // ISourceControl_h_
