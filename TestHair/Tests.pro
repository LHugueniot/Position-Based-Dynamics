TEMPLATE=app
LIBS+=-L/usr/local/lib -lgtest -lgtest_main -L$$PWD/../PBDLib/build -lPBDLib
CONFIG+=c++11

SOURCES += \
    main.cpp

INCLUDEPATH+= $$PWD/../PBDLib/include

QMAKE_RPATHDIR+= $$PWD/../PBDLib
