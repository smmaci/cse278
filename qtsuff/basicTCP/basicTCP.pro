QT += core
QT -= gui
QT += network

CONFIG += c++11

TARGET = basicTCP
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    mytcpsocket.cpp

HEADERS += \
    mytcpsocket.h
