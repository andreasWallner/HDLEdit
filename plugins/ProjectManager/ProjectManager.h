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

	QString name() const;
	QString description() const;
	QString version() const;
	QString provides() const;
	QStringList depends() const;
	void registerPlugin( PluginManager* manager);
};

#endif // ProjectManager_h_
