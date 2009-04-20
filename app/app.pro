TEMPLATE = app
TARGET = HDLEdit
DESTDIR = ./../bin
INCLUDEPATH += ./../
HEADERS += 
SOURCES += main.cpp
CONFIG += qt \
    warn_on \
    release
LIBS *= -lcore -L./../bin/plugins
