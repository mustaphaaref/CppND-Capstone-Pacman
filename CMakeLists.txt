cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(Pacman)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src)

set(PACMAN_HEADERS
src/Controller.h
src/Game.h
src/Renderer.h
)

set(PACMAN_SOURCES
src/Controller.cpp
src/Game.cpp
src/main.cpp
src/Renderer.cpp
)

add_executable(Pacman ${PACMAN_SOURCES} ${PACMAN_HEADERS})
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(Pacman ${SDL2_LIBRARIES})
