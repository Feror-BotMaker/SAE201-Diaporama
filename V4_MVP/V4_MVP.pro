QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    changeurvitesse.cpp \
    image.cpp \
    main.cpp \
    lecteurvue.cpp \
    modele.cpp \
    pageapropos.cpp \
    presentation.cpp

HEADERS += \
    changeurvitesse.h \
    image.h \
    lecteurvue.h \
    modele.h \
    pageapropos.h \
    presentation.h

FORMS += \
    changeurvitesse.ui \
    lecteurvue.ui \
    pageapropos.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
