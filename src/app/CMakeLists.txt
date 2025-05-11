set(target_name NoiseRemover)

add_executable(${target_name} WIN32
  app/main.cpp
  ${RESOURCES_DIR}/resources.qrc
  ${RESOURCES_DIR}/resource.rc
)

target_sources(
  ${target_name}
  PRIVATE
    app/main.cpp
)

target_link_libraries(
  ${target_name}
  PRIVATE
  window
)