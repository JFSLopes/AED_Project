cmake_minimum_required(VERSION 3.26)
project(AED_Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(AED_Project main.cpp
        code/source/App.cpp
        code/source/Class.cpp
        code/source/Schedule.cpp
        code/source/Student.cpp
        code/source/Subject.cpp
        code/source/Uc.cpp
        code/source/Display.cpp
        code/source/Change.cpp)
