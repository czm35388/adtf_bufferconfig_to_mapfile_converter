
set(LIB_NAME parser_lib)
set(LIB_TEST_NAME test_parser_lib)

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


# testing binary
add_executable(${LIB_TEST_NAME} ${LIB_TEST_NAME}.cpp)
target_link_libraries(${LIB_TEST_NAME} ${LIB_NAME})

# define test
add_test(
  NAME catch_test
  COMMAND $<TARGET_FILE:${LIB_TEST_NAME}> --success)