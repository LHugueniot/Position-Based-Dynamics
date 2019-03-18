TEMPLATE=app
LIBS+=-L/usr/local/lib -lgtest -lgtest_main -L../PBDLib/build -lPBDLib
CONFIG+=c++11

DEFINES+= CURRENT_DIR=$$PWD

SOURCES += src/main.cpp

OBJECTS_DIR+=obj/

TARGET= build/Tests

INCLUDEPATH+= ../PBDLib/include

#QMAKE_RPATHDIR+= $$PWD/../PBDLib
