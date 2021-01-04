
set(LIB_NAME parser_lib)

add_library(${LIB_NAME} 
    STATIC
        ${LIB_NAME}.cpp 
        ${LIB_NAME}.h
        ../../3rdparty/pugixml-1.10/src/pugixml.cpp)

target_include_directories(${LIB_NAME} 
    PRIVATE 
        ../../3rdparty/pugixml-1.10/src/
        ../../3rdparty/Catch2/
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR})