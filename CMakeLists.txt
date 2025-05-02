cmake_minimum_required(VERSION 3.22)

project(
  NoiseRemover
  VERSION 1.0
  LANGUAGES CXX RC
)

enable_language(CXX RC)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

# Генерация ресурса
set(CMAKE_RC_COMPILER_WORKS true)
set(CMAKE_RC_FLAGS "-fo${CMAKE_CURRENT_BINARY_DIR}/resource.res")

add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/resource.res
  COMMAND windres ${CMAKE_CURRENT_SOURCE_DIR}/resource.rc -O coff -o ${CMAKE_CURRENT_BINARY_DIR}/resource.res
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  VERBATIM
)

add_subdirectory(src)

# qt_add_resources(resources resources.qrc)