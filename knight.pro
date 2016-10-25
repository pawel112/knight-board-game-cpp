#-------------------------------------------------
#
# Project created by QtCreator 2016-08-25T01:15:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = knight
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    validation.cpp \
    tile.cpp \
    aboutwindow.cpp \
    ruleswindow.cpp \
    chooselanguage.cpp \
    settings.cpp \
    language.cpp \
    check_game.cpp \
    ai.cpp

HEADERS  += mainwindow.h \
    validation.h \
    tile.h \
    aboutwindow.h \
    ruleswindow.h \
    settings.h \
    main.h \
    language.h \
    chooselanguage.h \
    check_game.h \
    ai.h

FORMS    += mainwindow.ui \
    aboutwindow.ui \
    ruleswindow.ui \
    chooselanguage.ui

RESOURCES += \
    Images.qrc

DISTFILES += \
    TO_DO.txt

win32: RC_ICONS = Images\icon.ico
VERSION = 1.0
QMAKE_TARGET_COMPANY = Pawel Roszatycki
QMAKE_TARGET_PRODUCT = Game Knight
QMAKE_TARGET_DESCRIPTION = Game Knight

QT += xml svg
QTPLUGIN += qsvg
QTPLUGIN += qsvg qsvgicon
