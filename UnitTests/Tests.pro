TEMPLATE=app
LIBS+=-L/usr/local/lib -lgtest -lgtest_main -L$$PWD/../PBDLib/build -lPBDLib
CONFIG+=c++11

DEFINES+= CURRENT_DIR=$$PWD

SOURCES += src/main.cpp

OBJECTS_DIR+=obj/

TARGET= build/Tests

INCLUDEPATH+= $$PWD/../PBDLib/include

QMAKE_RPATHDIR+= $$PWD/../PBDLib
