#-------------------------------------------------
#
# Project created by QtCreator 2019-06-13T12:02:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProyectoUnico
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        Cuentas/cuenta.cpp \
        Entorno/entorno.cpp \
        Entorno/metodo_funcion.cpp \
        Entorno/simbolos.cpp \
        Expresiones/archivosder.cpp \
        Expresiones/conjuntos.cpp \
        Expresiones/entradas.cpp \
        Expresiones/regex.cpp \
        Herramientas/arreglos.cpp \
        Herramientas/entorno_clase.cpp \
        Herramientas/extensiones.cpp \
        Herramientas/objeto.cpp \
        PrimerRecorrido/operacion.cpp \
        PrimerRecorrido/primerrecorrido.cpp \
        PrimerRecorrido/segundorecorrido.cpp \
        errores.cpp \
        main.cpp \
        nodoast.cpp \
        principal.cpp\
        Analizadores/scanner.cpp\
        Analizadores/parser.cpp

HEADERS += \
        Cuentas/cuenta.h \
        Entorno/entorno.h \
        Entorno/metodo_funcion.h \
        Entorno/simbolos.h \
        Expresiones/archivosder.h \
        Expresiones/conjuntos.h \
        Expresiones/entradas.h \
        Expresiones/regex.h \
        Herramientas/arreglos.h \
        Herramientas/entorno_clase.h \
        Herramientas/extensiones.h \
        Herramientas/objeto.h \
        PrimerRecorrido/operacion.h \
        PrimerRecorrido/primerrecorrido.h \
        PrimerRecorrido/segundorecorrido.h \
        errores.h \
        nodoast.h \
        principal.h\
        Analizadores/scanner.h\
        Analizadores/parser.h

FORMS += \
        principal.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Analizadores/lexico.l \
    Analizadores/parser.y
