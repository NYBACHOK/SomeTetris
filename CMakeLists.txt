cmake_minimum_required(VERSION 3.24)
project(src)

set(CMAKE_CXX_STANDARD 17)

add_executable(src main.cpp Models/Imp/Shape.cpp Models/Imp/Matrix.cpp Models/Imp/GameManager.cpp Models/GameManager.h)
