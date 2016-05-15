QT += core
QT -= gui

TARGET = Zadanie4
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    funkcja.cpp \
    interpolacja.cpp \
    interpolacjawielomian.cpp \
    wielomian.cpp \
    calkowanie.cpp \
    newtoncotes.cpp \
    gauss.cpp \
    funkcjatrygonometryczna.cpp \
    funkcjazlozona1.cpp \
    funkcjazlozona2.cpp

HEADERS += \
    funkcja.h \
    interpolacja.h \
    interpolacjawielomian.h \
    wielomian.h \
    calkowanie.h \
    newtoncotes.h \
    gauss.h \
    funkcjatrygonometryczna.h \
    funkcjazlozona1.h \
    funkcjazlozona2.h

