TEMPLATE = app
TARGET = HDLEdit
DESTDIR = ./../bin
INCLUDEPATH += ../.

CONFIG += qt \
	warn_on \
	release

SOURCES += main.cpp

LIBS += -L./../bin/plugins -lcore
