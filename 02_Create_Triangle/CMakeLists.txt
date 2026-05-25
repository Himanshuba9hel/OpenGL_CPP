cmake_minimum_required(VERSION 3.16)

project(02_Create_Triangle LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(
    02_Create_Triangle

    main.cpp
    ../glad/src/glad.c
)

target_include_directories(
    02_Create_Triangle PRIVATE

    ../glad/include
)

target_link_libraries(
    02_Create_Triangle PRIVATE

    glfw
    OpenGL::GL
    dl
)

include(GNUInstallDirs)

install(
    TARGETS 02_Create_Triangle

    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
