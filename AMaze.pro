QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    gamestate.cpp \
    graphicobject.cpp \
    main.cpp \
    mainwindow.cpp \
    mapfield.cpp \
    movingobject.cpp \
    object.cpp \
    player.cpp \
    playergraphic.cpp \
    state.cpp

HEADERS += \
    gamestate.h \
    graphicobject.h \
    mainwindow.h \
    mapfield.h \
    movingobject.h \
    object.h \
    player.h \
    playergraphic.h \
    state.h

FORMS += \
    mainwindow.ui

INCLUDEPATH += E:\PROGRAMOWANIE\QT_projekty\SFML-2.0\include
DEPENDPATH += E:\PROGRAMOWANIE\QT_projekty\SFML-2.0\include

LIBS += -LE:\PROGRAMOWANIE\QT_projekty\LIBS\

CONFIG(debug, debug|release):  LIBS += -lsfml-audio-d -lsfml-system-d -lsfml-network-d -lsfml-main-d -lsfml-window-d -lsfml-graphics-d
CONFIG(release, release|debug):LIBS += -lsfml-audio -lsfml-system -lsfml-network -lsfml-main -lsfml-window -lsfml-graphics

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Config/window.txt
