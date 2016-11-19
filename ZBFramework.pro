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
    agamestate.cpp \
    gamestatemanager.cpp \
    test/mainmenu.cpp \
    test/level.cpp \
    test/bullet.cpp \
    test/enemy.cpp \
    test/game.cpp \
    test/health.cpp \
    test/myrect.cpp \
    test/score.cpp

HEADERS  += engine.h \
    texturemanager.h \
    vector2d.h \
    aactor.h \
    agamestate.h \
    gamestatemanager.h \
    test/mainmenu.h \
    test/level.h \
    test/bullet.h \
    test/enemy.h \
    test/game.h \
    test/health.h \
    test/myrect.h \
    test/score.h

FORMS +=

DISTFILES +=

RESOURCES += \
    space.qrc
