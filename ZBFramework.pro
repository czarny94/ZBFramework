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
<<<<<<< HEAD
    test/player/inputplayer.cpp \
    test/player/player.cpp \
    test/player/playerstate.cpp \
    test/player/playerstatemachine.cpp \
    test/player/movedleft.cpp \
    test/player/movedright.cpp \
    test/player/staticstate.cpp \
=======
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
>>>>>>> f6c4f537ae7b94716c7dc2db16e859895226721b
    test/pausemenu.cpp

HEADERS  += \
    core/agamestate.h \
    core/aprototype.h \
    core/engine.h \
    core/gamestatemanager.h \
    core/graphicsitemfactory.h \
    core/resourcemanager.h \
    core/vector2d.h \
<<<<<<< HEAD
    test/bullet.h \
    test/bulletprototype.h \
    test/enemy.h \
    test/enemyprototype.h \
    test/enemyspawner.h \
    test/gamegui.h \
    test/gameover.h \
    test/health.h \
    test/level.h \
    test/mainmenu.h \
    test/pixmapentity.h \
    test/score.h \
    test/player/inputplayer.h \
    test/player/player.h \
    test/player/playerstate.h \
    test/player/playerstatemachine.h \
    test/player/movedleft.h \
    test/player/movedright.h \
    test/player/staticstate.h \
=======
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
>>>>>>> f6c4f537ae7b94716c7dc2db16e859895226721b
    test/pausemenu.h

FORMS +=

DISTFILES +=

RESOURCES += \
    space.qrc

CONFIG += c++11
