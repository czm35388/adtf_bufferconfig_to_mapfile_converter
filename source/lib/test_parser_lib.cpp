#include <parser_lib.h>
#include <iostream>

#define CATCH_CONFIG_MAIN
#include "../../3rdparty/Catch2/catch.hpp"

// this macro is necessary, cause the test executable is not available in the source folder
#define TEST_FILE_DIR "../../../source/source/lib/test_files/"

// method for generating the path to the test xml file
std::string GenTestFilePath(std::string TestFileName)
{
    std::string strTestFilePath{TEST_FILE_DIR};
    strTestFilePath.append(TestFileName);
    return strTestFilePath;
}

TEST_CASE("Open existing xml file", "[open_xml_file]") 
{
    cParserLib oTestParser;
    REQUIRE(oTestParser.OpenBufferConfigFile(GenTestFilePath("input_file.xml")));
}

TEST_CASE("Open non existing xml file", "[open_non_existing_xml_file]")
{
    cParserLib oTestParser;
    REQUIRE_FALSE(oTestParser.OpenBufferConfigFile("non_existing.xml"));
}

TEST_CASE("Open with empty path", "[open_with_empty_path]")
{
    cParserLib oTestParser;
    REQUIRE_FALSE(oTestParser.OpenBufferConfigFile(""));
}