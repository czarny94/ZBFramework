#-------------------------------------------------
#
# Project created by QtCreator 2016-11-15T11:54:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

TARGET = ZBFramework
TEMPLATE = app


SOURCES += main.cpp\
        engine.cpp \
    texturemanager.cpp \
    vector2d.cpp \
    aactor.cpp \
    ascene.cpp \
    scenemanager.cpp

HEADERS  += engine.h \
    texturemanager.h \
    vector2d.h \
    aactor.h \
    ascene.h \
    scenemanager.h
