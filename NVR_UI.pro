#-------------------------------------------------
#
# Project created by QtCreator 2018-06-26T14:52:28
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NVR_UI
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
        nvr_main_ui.cpp \
    nvr_search_ipc_ui.cpp \
    nvr_video_layout_ui.cpp

HEADERS += \
        nvr_main_ui.h \
    nvr_layout_ui.h
ICON += src.png\
               windows.png\
               searh.png\
               IPC.png\
               SysSet.png\
               VideoLayout.png\
               VideoSet.png\
                IPC1.png\
               cheek.png\
               uncheek.png\
               search.png\
               add.png\
               removeall.png\
               remove.png\
               clock.png\
               OK.png\
               Cancel.png\
               user.png


#RC_FILE = NVR_UI_resource.rc
