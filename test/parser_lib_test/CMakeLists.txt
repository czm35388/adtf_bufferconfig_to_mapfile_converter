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

# Create the gcov target. Run coverage tests with 'make test_parser_lib_cov'
add_custom_target(${LIB_TEST_NAME}_cov
    COMMAND mkdir -p coverage
    COMMAND ${CMAKE_MAKE_PROGRAM} test
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )

set(OBJECT_DIR ${CMAKE_BINARY_DIR}/test/parser_lib_test/CMakeFiles/test_parser_lib.dir/*.gcno)

add_custom_command(TARGET ${LIB_TEST_NAME}_cov
    COMMAND echo "==== CODE - COVERAGE ===="
    COMMAND gcov -a -b ${CMAKE_SOURCE_DIR}/*.cpp -o ${OBJECT_DIR} -f | grep -A 5 "parser_lib.cpp" > CoverageSummary.tmp
    COMMAND cat CoverageSummary.tmp
    COMMAND echo "-- Coverage files have been output to ${CMAKE_BINARY_DIR}/coverage"
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/coverage
    )

add_custom_target(${LIB_TEST_NAME}_clean_up
    COMMAND echo "==== CLEAN - UP ===="
    COMMAND mv test_parser_lib.cpp.gcov ..
    COMMAND rm -fR *.gcov
    COMMAND mv ../test_parser_lib.cpp.gcov .
    COMMAND ls -l
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/coverage
    )

add_dependencies(${LIB_TEST_NAME}_cov ${LIB_TEST_NAME})