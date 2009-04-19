#include "plugins/core/PluginManager.h"

#include <QApplication>
#include <QtDebug>
#include <QTime>

int main( int argc, char* argv[]) {
	QApplication app( argc, argv);

	qDebug() << QTime::currentTime();

	PluginManager pluginManager;
	if( pluginManager.initialize())
		return 1;

	//return app.exec();
	return 0;
}
