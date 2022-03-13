cmake_minimum_required(VERSION 3.17)
project(image_extra)

set(CMAKE_CXX_STANDARD 14)

add_executable(image_extra app.cpp Image.cpp Image.h Rectangle.cpp Rectangle.h Point.cpp Point.h DrawShapes.cpp DrawShapes.h ImageProcessing.cpp ImageProcessing.h Console.cpp Console.h)