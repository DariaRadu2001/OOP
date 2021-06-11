QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin_login_form.cpp \
    auto.cpp \
    auto_repo.cpp \
    auto_tabelle_form.cpp \
    controller.cpp \
    kunde.cpp \
    kunde_menu_form.cpp \
    kunde_repo.cpp \
    login_form.cpp \
    main.cpp \
    mainwindow.cpp \
    sign_up_form.cpp

HEADERS += \
    admin_login_form.h \
    auto.h \
    auto_repo.h \
    auto_tabelle_form.h \
    controller.h \
    kunde.h \
    kunde_menu_form.h \
    kunde_repo.h \
    login_form.h \
    mainwindow.h \
    sign_up_form.h

FORMS += \
    admin_login_form.ui \
    auto_tabelle_form.ui \
    kunde_menu_form.ui \
    login_form.ui \
    mainwindow.ui \
    sign_up_form.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
