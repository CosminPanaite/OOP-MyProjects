cmake_minimum_required(VERSION 3.17)
project(OOP_SEMESTER_PROJECT)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(OOP_SEMESTER_PROJECT
        Coach.cpp
        Coach.h
        Controller.cpp
        Controller.h
        FieldPlayer.cpp
        FieldPlayer.h
        main.cpp
        Repository.cpp
        Repository.h
        Staff.cpp
        Staff.h
        TestClasses.cpp
        TestClasses.h
        Text_in.txt
        Text_out.txt
        UI.cpp
        UI.h)
