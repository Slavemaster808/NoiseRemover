set(target_name NoiseRemover)

# Первое, что делаем — ставим зависимость от ресурса
# add_custom_target(resource_gen ALL
#   DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/resource.res
# )

# Второе — создаём цель с зависимостью от resource_gen
add_executable(${target_name} WIN32
  app/main.cpp
  # ${CMAKE_CURRENT_BINARY_DIR}/resource.res
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

# Ставим зависимость на ресурс
# add_dependencies(${target_name} resource_gen)