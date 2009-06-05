cmake_minimum_required(VERSION 2.6)

find_package(Qt4 COMPONENTS QtCore QtGui QtSvg REQUIRED)
link_directories(${QT_LIBRARY_DIR})
include_directories(${QT_INCLUDES})

set(FRETBOARD_SOURCES fretboardwidget.cpp
                      guitar.cpp
                      guitar.h
                      guitartrainer.cpp
                      main.cpp
                      sound.cpp
                      sound.h
                      stavewidget.cpp)


qt4_wrap_cpp(FRETBOARD_MOC fretboardwidget.h guitartrainer.h stavewidget.h)
qt4_add_resources(FRETBOARD_RES fretboards.qrc)

add_executable(fretboard ${FRETBOARD_SOURCES}
                         ${FRETBOARD_MOC}
                         ${FRETBOARD_RES})

target_link_libraries(fretboard ${QT_QTCORE_LIBRARY}
                                ${QT_QTGUI_LIBRARY}
                                ${QT_QTSVG_LIBRARY})
