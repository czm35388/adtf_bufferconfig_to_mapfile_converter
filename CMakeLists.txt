cmake_minimum_required(VERSION 3.10.0)

# set the project name
set(bufferconfig_to_mapfile_converter)

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

add_subdirectory(source)
