cmake_minimum_required(VERSION 3.22)
project(dirruptor)
set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_STANDARD 23)

include_directories(deps/spdlog-1.x/include)
add_subdirectory(deps/spdlog-1.x)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC spdlog::spdlog_header_only)
