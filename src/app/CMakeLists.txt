set(target_name NoiseRemover)

add_executable(${target_name})

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

target_sources(
  ${target_name}
  PRIVATE
    app/main.cpp
)

target_link_libraries(
  ${target_name}
  PRIVATE
  window
  Qt6::Core
  Qt6::Gui
  Qt6::Widgets
)