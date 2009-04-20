TEMPLATE = lib
TARGET = core
INCLUDEPATH += ./../
DEFINES = CORE_LIBRARY
SOURCES += PluginManager.cpp \
    dialogs/CoreDumpDialog.cpp \
    IconProvider.cpp \
    dialogs/LogWindow.cpp \
    MimeDatabase.cpp
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
DESTDIR = ../../bin/plugins
FORMS += dialogs/CoreDumpDialog.ui \
    dialogs/LogWindow.ui
