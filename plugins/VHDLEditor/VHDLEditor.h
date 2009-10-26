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

	QString name() const;
	QString description() const;
	QString version() const;
	QString provides() const;
	QStringList depends() const;
	void registerPlugin( PluginManager* manager);
};

#endif // VHDLEditor_h_
