cmake_minimum_required(VERSION 3.10.0)

# set the project name
set(PROJECT_NAME bufferconfig_to_mapfile_converter)
project(${PROJECT_NAME} VERSION 0.0.1)

find_package(Catch2 REQUIRED)

# add the executable
add_executable(${PROJECT_NAME} main.cpp)
