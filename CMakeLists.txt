cmake_minimum_required(VERSION 3.5.1)

project(raystein)

set(OpenGL_GL_PREFERENCE GLVND)

find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)

include_directories(includes)

file(GLOB SOURCES src/*.cpp)

add_executable(raystein ${SOURCES})

target_compile_options(raystein PUBLIC)

target_link_libraries(raystein GL SDL2)
