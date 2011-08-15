#-------------------------------------------------
#
# Project created by QtCreator 2011-08-15T19:54:43
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = gameXO
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    player.cpp \
    humanplayer.cpp \
    randomplayer.cpp \
    values.cpp \
    smartplayer.cpp

HEADERS += \
    player.h \
    humanplayer.h \
    randomplayer.h \
    values.h \
    smartplayer.h
