#-------------------------------------------------
#
# Project created by QtCreator 2016-11-15T11:54:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

TARGET = ZBFramework
TEMPLATE = app

SOURCES += \
    core/agamestate.cpp \
    core/aprototype.cpp \
    core/engine.cpp \
    core/gamestatemanager.cpp \
    core/graphicsitemfactory.cpp \
    core/resourcemanager.cpp \
    core/vector2d.cpp \
    main.cpp \
    core/spritemanager.cpp \
    SpaceShooter/player/inputplayer.cpp \
    SpaceShooter/player/movedleft.cpp \
    SpaceShooter/player/movedright.cpp \
    SpaceShooter/player/player.cpp \
    SpaceShooter/player/playerstate.cpp \
    SpaceShooter/player/playerstatemachine.cpp \
    SpaceShooter/player/staticstate.cpp \
    SpaceShooter/bullet.cpp \
    SpaceShooter/bulletprototype.cpp \
    SpaceShooter/enemy.cpp \
    SpaceShooter/enemyprototype.cpp \
    SpaceShooter/enemyspawner.cpp \
    SpaceShooter/gamegui.cpp \
    SpaceShooter/gameover.cpp \
    SpaceShooter/health.cpp \
    SpaceShooter/level.cpp \
    SpaceShooter/mainmenu.cpp \
    SpaceShooter/pixmapentity.cpp \
    SpaceShooter/score.cpp \
    SpaceShooter/pausemenu.cpp

HEADERS  += \
    core/agamestate.h \
    core/aprototype.h \
    core/engine.h \
    core/gamestatemanager.h \
    core/graphicsitemfactory.h \
    core/resourcemanager.h \
    core/vector2d.h \
    core/spritemanager.h \
    SpaceShooter/player/inputplayer.h \
    SpaceShooter/player/movedleft.h \
    SpaceShooter/player/movedright.h \
    SpaceShooter/player/player.h \
    SpaceShooter/player/playerstate.h \
    SpaceShooter/player/playerstatemachine.h \
    SpaceShooter/player/staticstate.h \
    SpaceShooter/bullet.h \
    SpaceShooter/bulletprototype.h \
    SpaceShooter/enemy.h \
    SpaceShooter/enemyprototype.h \
    SpaceShooter/enemyspawner.h \
    SpaceShooter/gamegui.h \
    SpaceShooter/gameover.h \
    SpaceShooter/health.h \
    SpaceShooter/level.h \
    SpaceShooter/mainmenu.h \
    SpaceShooter/pixmapentity.h \
    SpaceShooter/score.h \
    SpaceShooter/pausemenu.h

FORMS +=

DISTFILES +=

RESOURCES += \
    space.qrc

CONFIG += c++11
