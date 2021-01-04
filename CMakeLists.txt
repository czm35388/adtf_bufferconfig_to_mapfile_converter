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


# add necessary source
add_subdirectory(source)

#------------------------------------------------
# TESTSECTION
#------------------------------------------------

# include the 'CTest' Modul
include(CTest)

# enable testing
enable_testing()

# specify compiler settings for code coverage
# these settings are only available for gcc and clang!
if (UNIX AND ENABLE_COVERAGE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g ")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
    if("${CMAKE_CXX_COMPILER_ID}" MATCHES "(Apple)?[Cc]lang")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-instr-generate -fcoverage-mapping")
    elseif(CMAKE_COMPILER_IS_GNUCXX)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ftest-coverage")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
    endif()
endif ()

# add the 'test' directory containing all test's
add_subdirectory(test)