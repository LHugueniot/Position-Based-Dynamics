TEMPLATE=app
LIBS+=-L/usr/local/lib -lgtest -lgtest_main -L$$PWD/../PBDLib -lPBDLib
CONFIG+=c++11

DEFINES+= CURRENT_DIR=$$PWD

SOURCES += \
    main.cpp

INCLUDEPATH+= $$PWD/../PBDLib
