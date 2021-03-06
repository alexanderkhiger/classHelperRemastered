#-------------------------------------------------
#
# Project created by QtCreator 2018-05-19T13:51:22
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = classHelperRemastered
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    Views/authview.cpp \
    Services/queryservice.cpp \
    Models/authmodel.cpp \
    Components/customlineedit.cpp \
    Components/customdroparea.cpp \
    Views/DatabaseTableViews/universityview.cpp \
    Models/DatabaseTableModels/universitymodel.cpp \
    Views/mainwindowview.cpp

HEADERS += \
    Views/authview.h \
    Services/queryservice.h \
    Models/authmodel.h \
    exception.h \
    Components/customdoublevalidator.h \
    Components/customsqlquerymodel.h \
    Components/customtableview.h \
    Components/customlineedit.h \
    Components/customdroparea.h \
    Views/databasetableviews/universityview.h \
    Views/DatabaseTableViews/commondatabasetableview.h \
    Models/DatabaseTableModels/commondatabasetablemodel.h \
    Models/DatabaseTableModels/universitymodel.h \
    Views/mainwindowview.h
