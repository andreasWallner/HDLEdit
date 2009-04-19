TEMPLATE = app
TARGET = HDLEdit
FORMS += CoreDumpDialog.ui
INCLUDEPATH += ./../../
DEFINES += LIB_BUILD
HEADERS += IPlugin.h \
    PluginManager.h \
    ISettingsEditor.h \
    IIconFactory.h \
    IMimeTypeManager.h \
    ILogger.h \
    IProjectManager.h \
    CoreDumpDialog.h \
    PluginGlobal.h
SOURCES += main.cpp \
    PluginManager.cpp \
    CoreDumpDialog.cpp
CONFIG += qt \
    warn_on \
    release
