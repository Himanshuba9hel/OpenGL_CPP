cmake_minimum_required(VERSION 3.16)

project(Hello_World LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(
    01_Create_Window

    src/main.cpp
    glad/src/glad.c
)

target_include_directories(
    01_Create_Window PRIVATE

    glad/include
)

target_link_libraries(
    01_Create_Window PRIVATE

    glfw
    OpenGL::GL
    dl
)

include(GNUInstallDirs)

install(
    TARGETS 01_Create_Window

    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
