set(APP_NAME xml_to_mapfile_converter)

add_executable(${APP_NAME} ${APP_NAME}.cpp)

target_link_libraries(${APP_NAME} 
    PRIVATE 
        parser_lib)

target_include_directories(${APP_NAME} 
    PRIVATE 
        ../../3rdparty/Clara/)

install(TARGETS ${APP_NAME} 
    DESTINATION 
        bin)