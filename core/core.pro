TEMPLATE = lib
TARGET = core
DESTDIR = ../bin/plugins
INCLUDEPATH += ../.
INCLUDEPATH += ../interfaces
DEFINES += CORE_LIBRARY

HEADERS += \
	../interfaces/PluginManager.h

HEADERS += \
	IconProvider.h \
	MimeDatabase.h \
	SettingsEditor.h \
	dialogs/LogWindow.h \
	dialogs/CoreDumpDialog.h \
	dialogs/DefaultEditorDialog.h

SOURCES += \
	../interfaces/IPlugin.cpp \
	../interfaces/IEditor.cpp \
	../interfaces/ISourceControl.cpp \
	../interfaces/IProjectManager.cpp \
	../interfaces/ISettingsEngine.cpp

SOURCES += \
	PluginManager.cpp \
	IconProvider.cpp \
	MimeDatabase.cpp \
	dialogs/LogWindow.cpp \
	dialogs/CoreDumpDialog.cpp \
	dialogs/DefaultEditorDialog.cpp

FORMS += dialogs/LogWindow.ui \
	dialogs/CoreDumpDialog.ui \
	dialogs/DefaultEditorDialog.ui
