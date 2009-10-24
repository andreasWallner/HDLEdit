#ifndef ProjectManager_h_
#define ProjectManager_h_

#include <QObject>
#include "core/IProjectManager.h"

class ProjectManager : public QObject, public IProjectManager
{
	Q_OBJECT
	Q_INTERFACES(IPlugin IProjectManager)

public:
	ProjectManager();

	virtual QString name() const;
	virtual QString description() const;
	virtual QString version() const;
	virtual QString provides() const;
	virtual QStringList depends() const;
	virtual void registerPlugin( PluginManager* manager);
};

#endif // ProjectManager_h_
