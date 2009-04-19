#ifndef IIconFactory_h_
#define IIconFactory_h_

#include "IPlugin.h"

class IIconFactory : public IPlugin
{
public:
	virtual ~IIconFactory() {}

};

Q_DECLARE_INTERFACE( IIconFactory, "com.HDLEdit.IconFactory/1.0");

#endif // IIconFactory_h_
