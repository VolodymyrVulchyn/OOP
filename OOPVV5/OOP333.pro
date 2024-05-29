QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ShoppingCartTest.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    BrakeDisc.h \
    BrakePad.h \
    CoolingSystem.h \
    Engine.h \
    FuelSystem.h \
    IdGenerator.h \
    Lights.h \
    Oil.h \
    Part.h \
    Radiator.h \
    ShoppingCart.h \
    SparkPlug.h \
    Suspension.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    OOP333_uk_UA.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
