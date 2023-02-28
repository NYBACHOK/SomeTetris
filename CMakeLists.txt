cmake_minimum_required(VERSION 3.24)
project(src)

set(CMAKE_CXX_STANDARD 17)

add_executable(src main.cpp Models/Imp/Matrix.cpp Models/Matrix.h Managers/Matrix_manager.cpp Managers/Matrix_manager.h Models/Shape.h Models/Imp/Cube.cpp Models/Cube.h)
