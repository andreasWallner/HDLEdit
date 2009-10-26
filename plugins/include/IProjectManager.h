#ifndef IProjectManager_h_
#define IProjectManager_h_

#include "IPlugin.h"

class CORE_EXPORT IProjectManager : public IPlugin
{
public:
	virtual ~IProjectManager();

};

Q_DECLARE_INTERFACE( IProjectManager, "com.HDLEdit.ProjectManager/1.0");

#endif // IProjectManager_h_
