cmake_minimum_required(VERSION 3.16)

project(OpenGL_CPP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(OpenGL_CPP
    main.cpp
    Setup.md
)

include(GNUInstallDirs)
install(TARGETS OpenGL_CPP
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
add_subdirectory(01_Create_Window)
add_subdirectory(02_Create_Triangle)
add_subdirectory(03_SetUp_GLEW)
add_subdirectory(04_Vertex_Buffers_N_Drawing_Triangle)
add_subdirectory(05_Vertex_Attributes_N_Layouts)
add_subdirectory(06_Shader)
add_subdirectory(07_Shader_Files)
add_subdirectory(08_Index_Buffers)
add_subdirectory(09_Dealing_with_Errors)
