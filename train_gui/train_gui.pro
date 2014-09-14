#-------------------------------------------------
#
# Project created by QtCreator 2014-08-08T16:09:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = train_gui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h

FORMS    += mainwindow.ui


unix|win32: LIBS += -lboost_system

unix|win32: LIBS += -lboost_thread




win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../rs_train/release/ -lrs_train
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../rs_train/debug/ -lrs_train
else:unix: LIBS += -L$$OUT_PWD/../rs_train/ -lrs_train

INCLUDEPATH += $$PWD/../rs_train/include
DEPENDPATH += $$PWD/../rs_train
