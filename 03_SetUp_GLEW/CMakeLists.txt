cmake_minimum_required(VERSION 3.16)

project(02_Create_Triangle LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)

add_executable(
    03_SetUp_GLEW
    main.cpp
    ../glad/src/glad.c
)

target_include_directories(
    03_SetUp_GLEW PRIVATE
    ../glad/include
)

target_link_libraries(
    03_SetUp_GLEW PRIVATE
    OpenGL::GL
    GLEW::GLEW
    glfw
    dl
)

include(GNUInstallDirs)

install(
    TARGETS 03_SetUp_GLEW
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
