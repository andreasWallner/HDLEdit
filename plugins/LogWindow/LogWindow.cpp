#include "LogWindow.h"

#include <QString>
#include <QStringList>

LogWindow::LogWindow()
{
}
QString LogWindow::name() const
{
	return "LogWindow";
}

QString LogWindow::version() const
{
	return "0.1";
}

QString LogWindow::provides() const
{
	return "base/logger";
}

QStringList LogWindow::depends() const
{
	QStringList list;
	list << "base/iconmanager";
	return list;
}

void LogWindow::registerPlugin( PluginManager* manager)
{
}

Q_EXPORT_PLUGIN2(LogWindow, LogWindow);
