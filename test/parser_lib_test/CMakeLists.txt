set(LIB_NAME parser_lib)
set(LIB_TEST_NAME test_parser_lib)

# testing binary
add_executable(${LIB_TEST_NAME} ${LIB_TEST_NAME}.cpp)
target_link_libraries(${LIB_TEST_NAME} ${LIB_NAME})

target_include_directories(${LIB_TEST_NAME} PRIVATE ../../source/lib/)

# define test
add_test( 
    NAME 
        ${LIB_TEST_NAME} 
    COMMAND 
        ${LIB_TEST_NAME})
        
# copy the test files to the binary folder
file(
    COPY 
        ${CMAKE_CURRENT_SOURCE_DIR}/test_files
    DESTINATION 
        ${CMAKE_CURRENT_BINARY_DIR}/)