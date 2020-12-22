QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    UI/CLI/simpleoutput.cpp \
    UI/CLI/textoutput.cpp \
    UI/textformater.cpp \
    app.cpp \
    core/coreadapter.cpp \
    core/duplchecker.cpp \
    core/hashgenerator.cpp \
    core/md5hashgenerator.cpp \
    core/smarthashdchecker.cpp \
    main.cpp \
    UI/GUI/mainwindow.cpp

HEADERS += \
    ICore.h \
    IPipeUI.h \
    UI/CLI/simpleoutput.h \
    UI/CLI/textoutput.h \
    UI/textformater.h \
    app.h \
    core/IDuplChecker.h \
    core/IHashGenerator.h \
    core/coreadapter.h \
    core/duplchecker.h \
    core/filespair.h \
    core/hashgenerator.h \
    core/md5hashgenerator.h \
    core/smarthashdchecker.h \
    UI/GUI/mainwindow.h

FORMS += \
    UI/GUI/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
