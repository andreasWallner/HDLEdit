TEMPLATE = app
TARGET = HDLEdit
DESTDIR = ./../bin
INCLUDEPATH += ../plugins
CONFIG += qt \
	warn_on \
	release

HEADERS +=
SOURCES += main.cpp

LIBS += -L./../bin/plugins -lcore
