#include "interfaces/PluginManager.h"

#include <QApplication>
#include <QtDebug>

int main( int argc, char* argv[])
{
	QApplication app( argc, argv);

	PluginManager pluginManager;
	if( pluginManager.initialize())
		return 1;

	qDebug() << "initialized pluginManager";

	//return app.exec();
	return 0;
}
