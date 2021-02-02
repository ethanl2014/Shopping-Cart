#-------------------------------------------------
#
# Project created by QtCreator 2018-04-15T23:58:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    observerdialog.cpp \
    pushbutton.cpp \
    cart.cpp \
    addbutton.cpp

HEADERS  += mainwindow.h \
    observerdialog.h \
    pushbutton.h \
    cart.h \
    addbutton.h \
    bird.h \
    pet.h \
    dog.h \
    cat.h \
    fish.h \
    sortablevector.h \
    bubblesorttemplate.h \
    bubblesortincreasing.h \
    petdatabasesortable.h \
    petdatabasesortablebyname.h \
    bundle.h \
    sortablebundle.h \
    bundledatabasesortablebyname.h \
    visitor.h \
    entity.h \
    countingvisitor.h \
    directory.h \
    builder.h \
    expbuilder.h \
    expparser.h

FORMS    += mainwindow.ui \
    observerdialog.ui
