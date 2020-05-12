cmake_minimum_required(VERSION 3.5)

project(timeline-app)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)

add_executable(timeline-app
  main.cpp
  timelinelayer.ui
  timelinelayerframe.ui
  TimelineLayer.cpp
  TimelineLayerFrame.cpp
  EditableLabelWidget.cpp
  editablelabelwidget.ui
  resources.qrc
  )

target_link_libraries(timeline-app Qt5::Core Qt5::Widgets Qt5::Gui)

