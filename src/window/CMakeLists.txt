set(target_name window)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

add_library(${target_name} STATIC
  window/mainwindow.cpp
  window/mainwindow.hpp)

target_include_directories(
  ${target_name}
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(
    ${target_name}
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)