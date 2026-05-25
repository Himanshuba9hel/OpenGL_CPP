cmake_minimum_required(VERSION 3.16)

project(OpenGL_CPP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(OpenGL_CPP main.cpp)

include(GNUInstallDirs)
install(TARGETS OpenGL_CPP
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
add_subdirectory(01_Create_Window)

add_subdirectory(02_Create_Triangle)
