cmake_minimum_required(VERSION 3.9)
project(lab1)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(lab1
        apple-pen-main.cpp
        apple-pen.cpp
        apple-pen.h
        apple.cpp
        apple.h
        Makefile
        pen.cpp
        pen.h
        pineapple-pen-main.cpp
        pineapple-pen.cpp
        pineapple-pen.h
        pineapple.cpp
        pineapple.h
        ppap.cpp)
