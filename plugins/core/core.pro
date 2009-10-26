TEMPLATE = lib
TARGET = core
DESTDIR = ../../bin/plugins
INCLUDEPATH += ../include
DEFINES = CORE_LIBRARY

HEADERS += \
	IconProvider.h \
	PluginManager.h \
	MimeDatabase.h \
	SettingsEditor.h \
	dialogs/LogWindow.h \
	dialogs/CoreDumpDialog.h \
	dialogs/DefaultEditorDialog.h

SOURCES += \
	IPlugin.cpp \
	IEditor.cpp \
	IProjectManager.cpp \
	ISettingsEngine.cpp \
	PluginManager.cpp \
	IconProvider.cpp \
	MimeDatabase.cpp \
	dialogs/LogWindow.cpp \
	dialogs/CoreDumpDialog.cpp \
	dialogs/DefaultEditorDialog.cpp

FORMS += dialogs/LogWindow.ui \
	dialogs/CoreDumpDialog.ui \
	dialogs/DefaultEditorDialog.ui
