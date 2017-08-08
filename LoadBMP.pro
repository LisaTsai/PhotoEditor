#-------------------------------------------------
#
# Project created by QtCreator 2014-08-15T14:07:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LoadBMP
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += D:/Database/NTU/MSVC/myCV/myCV\

debug{
    LIBS += D:/Database/NTU/MSVC/myCV/Debug/myCV.lib\
}

release{
    LIBS += D:/Database/NTU/MSVC/myCV/Release/myCV.lib\
}

