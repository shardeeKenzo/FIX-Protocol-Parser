cmake_minimum_required(VERSION 3.30)
project(FIX_Parser)

set(CMAKE_CXX_STANDARD 23)

add_executable(FIX_Parser main.cpp
        Reader.cpp
        Reader.h
        FIXParser.cpp
        FIXParser.h)
