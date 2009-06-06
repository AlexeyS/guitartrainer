cmake_minimum_required(VERSION 2.6)

find_package(Qt4 COMPONENTS QtCore QtGui QtSvg REQUIRED)
link_directories(${QT_LIBRARY_DIR})
include_directories(${QT_INCLUDES})

set(GT_SOURCES FretboardWidget.cpp
               Guitar.cpp
               Guitar.h
               GuitarTrainer.cpp
               main.cpp
               Sound.cpp
               Sound.h
               StaveWidget.cpp)


qt4_wrap_cpp(GT_MOC FretboardWidget.h
                    GuitarTrainer.h
                    StaveWidget.h
                    NoteButton.h
                    NotePanel.h)

qt4_add_resources(GT_RES fretboards.qrc)

add_executable(guitartrainer ${GT_SOURCES}
                             ${GT_MOC}
                             ${GT_RES})

target_link_libraries(guitartrainer ${QT_QTCORE_LIBRARY}
                                    ${QT_QTGUI_LIBRARY}
                                    ${QT_QTSVG_LIBRARY})
