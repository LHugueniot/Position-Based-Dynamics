TEMPLATE=app
LIBS+=-L/usr/local/lib -lgtest -lgtest_main -L$$PWD/../PBDHair -lPBDHair
CONFIG+=c++11

SOURCES += \
    main.cpp

INCLUDEPATH+= $$PWD/../PBDHair
