cmake_minimum_required(VERSION 3.29)
project(CSCI_335_project_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CSCI_335_project_1
    File.cpp
    File.hpp
    Folder.cpp
    Folder.hpp
    InvalidFormatException.hpp
    MyTests.cpp)
