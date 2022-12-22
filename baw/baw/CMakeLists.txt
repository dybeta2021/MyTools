cmake_minimum_required(VERSION 3.23)
project(baw)

set(CMAKE_CXX_STANDARD 23)

include_directories(baw)
aux_source_directory(baw BAW)

add_executable(baw main.cpp ${BAW})
