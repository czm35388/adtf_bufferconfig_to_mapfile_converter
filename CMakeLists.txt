cmake_minimum_required(VERSION 3.10.0)

# set the project name
set(PROJECT_NAME bufferconfig_to_mapfile_converter)

project(${PROJECT_NAME} VERSION 0.1.0)

# Version must be changed manually #
set(CONVERTER_VERSION_MAJOR 0)
set(CONVERTER_VERSION_MINOR 1)
set(CONVERTER_VERSION_PATCH 0)

add_definitions(
    -DCONVERTER_VERSION_MAJOR=${CONVERSION_VERSION_MAJOR}
    -DCONVERTER_VERSION_MINOR=${CONVERSION_VERSION_MINOR}
    -DCONVERTER_VERSION_PATCH=${CONVERSION_VERSION_PATCH}
)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# enable testing
include(CTest)
enable_testing()

# add necessary source
add_subdirectory(source)


