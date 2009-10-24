TEMPLATE = lib
TARGET = core
DESTDIR = ../../bin/plugins
INCLUDEPATH += ./../
DEFINES = CORE_LIBRARY

HEADERS += PluginManager.h \
    IIconFactory.h \
    ILogger.h \
    IMimeTypeManager.h \
    IPlugin.h \
    IProjectManager.h \
    ISettingsEditor.h \
    PluginGlobal.h \
    dialogs/CoreDumpDialog.h \
    IconProvider.h \
    dialogs/LogWindow.h \
    MimeDatabase.h

SOURCES += PluginManager.cpp \
    IconProvider.cpp \
    MimeDatabase.cpp \
    dialogs/LogWindow.cpp \
    dialogs/CoreDumpDialog.cpp

FORMS += dialogs/CoreDumpDialog.ui \
    dialogs/LogWindow.ui
