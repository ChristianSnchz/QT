#-------------------------------------------------
#
# Project created by QtCreator 2015-07-15T17:56:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = proyecto
TEMPLATE = app


SOURCES += main.cpp\
        principal.cpp \
    registrar.cpp \
    reparar.cpp \
    cambiarestado.cpp \
    retirar.cpp \
    artefacto.cpp \
    cpersona.cpp \
    bitacora.cpp \
    eliminar.cpp

HEADERS  += principal.h \
    registrar.h \
    reparar.h \
    cambiarestado.h \
    retirar.h \
    artefacto.h \
    cpersona.h \
    bitacora.h \
    eliminar.h

FORMS    += principal.ui \
    registrar.ui \
    reparar.ui \
    cambiarestado.ui \
    retirar.ui \
    bitacora.ui \
    eliminar.ui

RESOURCES += \
    imagen.qrc
