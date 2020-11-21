cmake_minimum_required(VERSION 3.10.0)

# set the project name
set(PROJECT_NAME bufferconfig_to_mapfile_converter)
project(${PROJECT_NAME} VERSION 0.0.1)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(source)
