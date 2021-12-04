QT       += core gui sql \
            multimedia \
            serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    chat1.cpp \
    chat2.cpp \
    connection.cpp \
    employe.cpp \
    les_services.cpp \
    lgoin_bd.cpp \
    log_in.cpp \
    login_button.cpp \
    main.cpp \
    mainwindow.cpp \
    securite.cpp

HEADERS += \
    arduino.h \
    chat1.h \
    chat2.h \
    connection.h \
    employe.h \
    les_services.h \
    lgoin_bd.h \
    log_in.h \
    login_button.h \
    mainwindow.h \
    securite.h

FORMS += \
    chat1.ui \
    chat2.ui \
    les_services.ui \
    log_in.ui \
    login_button.ui \
    mainwindow.ui \
    securite.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    click.wav
