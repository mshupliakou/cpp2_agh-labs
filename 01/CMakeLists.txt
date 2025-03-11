cmake_minimum_required(VERSION 3.10)
project(lab)

set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES ON)

if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "In-source builds are not allowed.")
endif()

add_definitions(-DPROJECTPATH=\"${PROJECT_SOURCE_DIR}\")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_DEBUG "-Wall")
set(CMAKE_CXX_FLAGS_RELEASE "-Wall")

# Включаем директорию с заголовочными файлами
include_directories(${PROJECT_SOURCE_DIR}/include)

# Список исходных файлов
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

# Добавляем исполнимый файл
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/main.cpp ${SOURCES})

# Линковка с математической библиотекой
target_link_libraries(${PROJECT_NAME} m)
