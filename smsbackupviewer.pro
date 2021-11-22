QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    address.cpp \
    helper.cpp \
    main.cpp \
    mainwindow.cpp \
    message.cpp \
    multimediamessage.cpp \
    part.cpp \
    smscollection.cpp \
    smsmap.cpp \
    textmessage.cpp

HEADERS += \
    address.h \
    helper.h \
    mainwindow.h \
    message.h \
    multimediamessage.h \
    part.h \
    smscollection.h \
    smsmap.h \
    textmessage.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    smsbackupviewer_en_US.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
