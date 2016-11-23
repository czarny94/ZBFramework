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
    agamestate.cpp \
    gamestatemanager.cpp \
    test/mainmenu.cpp \
    test/level.cpp \
    test/bullet.cpp \
    test/enemy.cpp \
    test/health.cpp \
    test/score.cpp \
    resourcemanager.cpp \
    test/player.cpp \
    test/enemyprototype.cpp \
    aprototype.cpp \
    graphicsitemfactory.cpp \
    test/enemyspawner.cpp \
    test/bulletprototype.cpp

HEADERS  += engine.h \
    texturemanager.h \
    vector2d.h \
    agamestate.h \
    gamestatemanager.h \
    test/mainmenu.h \
    test/level.h \
    test/bullet.h \
    test/enemy.h \
    test/health.h \
    test/score.h \
    resourcemanager.h \
    test/player.h \
    test/enemyprototype.h \
    aprototype.h \
    graphicsitemfactory.h \
    test/enemyspawner.h \
    test/bulletprototype.h

FORMS +=

DISTFILES +=

RESOURCES += \
    space.qrc
