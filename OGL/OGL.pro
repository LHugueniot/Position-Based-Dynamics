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


LIBS +=  -L../PBDLib/build -lPBDLib -lglut -lGL -lGLU

INCLUDEPATH+= /usr/local/bin/ include ../PBDLib/include

SOURCES +=  $$files($$PWD/src/*.cpp)

HEADERS += $$files($$PWD/include/*.h)

MOC_DIR +=moc

OBJECTS_DIR+=obj


FORMS += ui/mainwindow.ui

#QMAKE_RPATHDIR+= ../PBDLib

QMAKE_CXXFLAGS+=-O3
