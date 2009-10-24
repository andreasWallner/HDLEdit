TEMPLATE = lib
TARGET = core
DESTDIR = ../../bin/plugins
INCLUDEPATH += ./../
DEFINES = CORE_LIBRARY

HEADERS += PluginGlobal.h \
	IPlugin.h \
	IEditor.h \
	IProjectManager.h \
	ISettingsEditor.h \
	IconProvider.h \
	PluginManager.h \
	MimeDatabase.h \
	SettingsEditor.h \
	dialogs/LogWindow.h \
	dialogs/CoreDumpDialog.h \
	dialogs/DefaultEditorDialog.h

SOURCES += PluginManager.cpp \
	IconProvider.cpp \
	MimeDatabase.cpp \
	dialogs/LogWindow.cpp \
	dialogs/CoreDumpDialog.cpp \
	dialogs/DefaultEditorDialog.cpp

FORMS += dialogs/LogWindow.ui \
	dialogs/CoreDumpDialog.ui \
	dialogs/DefaultEditorDialog.ui
