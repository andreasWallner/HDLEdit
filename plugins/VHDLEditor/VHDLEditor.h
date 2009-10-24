#ifndef VHDLEditor_h_
#define VHDLEditor_h_

#include <QObject>
#include "core/IPlugin.h"

class VHDLEditor : public QObject, public IPlugin
{
	Q_OBJECT
	Q_INTERFACES(IPlugin)

public:
	VHDLEditor();

	virtual QString name() const;
	virtual QString description() const;
	virtual QString version() const;
	virtual QString provides() const;
	virtual QStringList depends() const;
	virtual void registerPlugin( PluginManager* manager);
};

#endif // VHDLEditor_h_
