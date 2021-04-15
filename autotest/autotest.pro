QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT       += serialport

QT       += charts

QT       += network

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    analysisdata.cpp \
    analysispac.cpp \
    dataexplain.cpp \
    drawform.cpp \
    inittelemetrytable.cpp \
    main.cpp \
    rcform.cpp \
    rtpainter.cpp \
    serialform.cpp \
    serialport.cpp \
    tableform.cpp \
    telemetryform.cpp \
    treewidgettelemetry.cpp \
    udpport.cpp \
    widget.cpp

HEADERS += \
    analysisdata.h \
    analysispac.h \
    dataexplain.h \
    drawform.h \
    inittelemetrytable.h \
    rcform.h \
    rtpainter.h \
    serialform.h \
    serialport.h \
    tableform.h \
    telemetryform.h \
    treewidgettelemetry.h \
    udpport.h \
    widget.h

FORMS += \
    drawform.ui \
    rcform.ui \
    serialform.ui \
    tableform.ui \
    telemetryform.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=

RC_ICONS = icon.ico
