#-------------------------------------------------
#
# Project created by QtCreator 2011-09-17T21:46:47
#
#-------------------------------------------------

QT       += core gui sql

TARGET = KatekistaFriend
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    msqkf_catalogosdao.cpp \
    msqkf_constantes.cpp \
    msqkf_daoutil.cpp \
    msqkf_catalogosservice.cpp \
    msqkf_servicefactory.cpp \
    msqkf_catalogosdto.cpp \
    msqkf_escuela.cpp \
    msqkf_niveleducativo.cpp \
    msqkf_loggerfactory.cpp \
    msqkf_logger.cpp \
    msqkf_gradoescolar.cpp \
    msqkf_dialogocapturaalumno.cpp \
    msqkf_sacramento.cpp \
    pollo.cpp

HEADERS  += mainwindow.h \
    msqkf_catalogosdao.h \
    msqkf_constantes.h \
    msqkf_daoutil.h \
    msqkf_catalogosservice.h \
    msqkf_servicefactory.h \
    msqkf_catalogosdto.h \
    msqkf_escuela.h \
    msqkf_niveleducativo.h \
    msqkf_loggerfactory.h \
    msqkf_logger.h \
    msqkf_gradoescolar.h \
    msqkf_dialogocapturaalumno.h \
    msqkf_sacramento.h \
    pollo.h

FORMS    += mainwindow.ui \
    msqkf_dialogocapturaalumno.ui

RESOURCES += \
    resources/icons32.qrc \
    resources/queryXmls.qrc

OTHER_FILES += \
    resources/xmls/conf/databaseDatasources.xml


















