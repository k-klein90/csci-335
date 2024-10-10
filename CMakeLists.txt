cmake_minimum_required(VERSION 3.29)
project(csci_335)

set(CMAKE_CXX_STANDARD 14)

include_directories(project-1)

add_executable(csci_335
    project-1/File.cpp
    project-1/File.hpp
    project-1/Folder.cpp
    project-1/Folder.hpp
    project-1/InvalidFormatException.hpp
    project-1/MyTests.cpp)
