
set(LIB_NAME parser_lib)

# add the executable
add_library(${LIB_NAME} STATIC ${LIB_NAME}.cpp)

target_include_directories(${LIB_NAME} PUBLIC ../../3rdparty/pugixml-1.10/)