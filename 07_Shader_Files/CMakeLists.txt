cmake_minimum_required(VERSION 3.16)

project(07_Shader_Files LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)

add_executable(
    07_Shader_Files
    main.cpp
    ../glad/src/glad.c
    res/shaders/Basic.shader
)

target_include_directories(
    07_Shader_Files PRIVATE
    ../glad/include
)

target_link_libraries(
    07_Shader_Files PRIVATE
    OpenGL::GL
    GLEW::GLEW
    glfw
    dl
)

include(GNUInstallDirs)

install(
    TARGETS 07_Shader_Files
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
