#-------------------------------------------------
#
# Project created by QtCreator 2018-12-23T17:36:58
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OGL
TEMPLATE = app

CONFIG+=c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


LIBS += -L$$(PWD)/../PBDLib/build -lPBDLib -lglut -lGL -lGLU

INCLUDEPATH+= /usr/local/bin/ $$(PWD)/include $$PWD/../PBDLib/include

SOURCES +=  $$(PWD)/src/main.cpp \
            $$(PWD)/src/mainwindow.cpp \
            $$(PWD)/src/glwidget.cpp \
            $$(PWD)/src/trackballcam.cpp

HEADERS +=  $$(PWD)/include/mainwindow.h \
            $$(PWD)/include/glwidget.h \
            $$(PWD)/include/trackballcam.h

FORMS +=    $$(PWD)/moc/mainwindow.ui

QMAKE_RPATHDIR+= $$PWD/../PBDLib
#win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../ClothLib/release/ -lClothSimLib
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../ClothLib/debug/ -lClothSimLib
#else:unix: LIBS += -L$$OUT_PWD/../ClothLib/ -lClothSimLib

#INCLUDEPATH += $$PWD/../ClothLib
#DEPENDPATH += $$PWD/../ClothLib

QMAKE_CXXFLAGS+=-O3
