cmake_minimum_required(VERSION 3.16)

project(10_Uniforms LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)

add_executable(
    10_Uniforms
    main.cpp
    ../glad/src/glad.c
    res/shaders/Basic.shader
)

target_include_directories(
    10_Uniforms PRIVATE
    ../glad/include
)

target_link_libraries(
    10_Uniforms PRIVATE
    OpenGL::GL
    GLEW::GLEW
    glfw
    dl
)

include(GNUInstallDirs)

install(
    TARGETS 10_Uniforms
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
