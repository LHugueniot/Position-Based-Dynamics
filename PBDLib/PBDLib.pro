#-------------------------------------------------
#
# Project created by QtCreator 2019-02-19T12:27:13
#
#-------------------------------------------------

QT       += widgets opengl

TARGET = build/PBDLib
TEMPLATE = lib

DEFINES += PBDLIB_LIBRARY #MODEL_DIR='$${PWD}'

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS #'CURRENT_DIR=$$(PWD)'

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#MOC_DIR +=

INCLUDEPATH+=/home/datlucien/assimp/include include
<<<<<<< HEAD

HEADERS +=  include/kernel.h \
            include/PBDLib \
            include/pbdobject.h \
            include/PBDLib \
            include/point.h \
            include/constraint.h \
            include/indexDuo.h \
            include/solver.h

SOURCES +=  src/kernel.cpp \
            src/pbdobject.cpp \
            src/point.cpp \
            src/constraint.cpp \
            src/solver.cpp

OBJECTS_DIR+= obj/

=======

HEADERS +=  $$(PWD)/include/kernel.h \
            $$(PWD)/include/PBDLib \
            $$(PWD)/include/pbdlib_global.h \
            $$(PWD)/include/pbdobject.h \
            $$(PWD)/include/PBDLib \
            $$(PWD)/include/point.h \
    include/constraint.h \
    include/vec3duo.h

SOURCES +=  $$(PWD)/src/kernel.cpp \
            $$(PWD)/src/pbdobject.cpp \
            $$(PWD)/src/point.cpp \
    $$(PWD)/src/constraint.cpp

OBJECTS_DIR+=   $$(PWD)/obj/

>>>>>>> 6e9392ae1e5b6d2bf5c7fbb41f5ea908e8b4dbad
LIBS+= -lassimp

unix {
    #target.path = $$PWD/include
    #INSTALLS += target
}
