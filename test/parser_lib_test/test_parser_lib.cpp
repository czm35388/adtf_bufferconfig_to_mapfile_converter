#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <iostream>
#include <parser_lib.h>

TEST_CASE("Open existing xml file", "[open_xml_file]") 
{
    cParserLib oTestParser;
    REQUIRE(oTestParser.OpenBufferConfigFile("./test_files/example_file.xml"));
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

TEST_CASE("Check input node parsing", "[input_parsing]")
{
    cParserLib oTestParser;
    REQUIRE(oTestParser.OpenBufferConfigFile("./test_files/simple_input_file.xml"));
    REQUIRE(oTestParser.GetInputCount() == 3);
    REQUIRE(oTestParser.GetBufferCount() == 3);
    REQUIRE(oTestParser.GetStructCount() == 3);
    REQUIRE(oTestParser.GetElementCount() == 3);
}

TEST_CASE("Check output node parsing", "[output_parsing]")
{
    cParserLib oTestParser;
    REQUIRE(oTestParser.OpenBufferConfigFile("./test_files/simple_output_file.xml"));
    REQUIRE(oTestParser.GetOutputCount() == 3);
    REQUIRE(oTestParser.GetBufferCount() == 3);
    REQUIRE(oTestParser.GetStructCount() == 3);
    REQUIRE(oTestParser.GetElementCount() == 3);
}

TEST_CASE("Check mixed xml file", "[mixed_parsing]")
{
    cParserLib oTestParser;
    REQUIRE(oTestParser.OpenBufferConfigFile("./test_files/example_file.xml"));
    REQUIRE(oTestParser.GetInputCount() == 1);
    REQUIRE(oTestParser.GetOutputCount() == 2);
    REQUIRE(oTestParser.GetBufferCount() == 3);
    REQUIRE(oTestParser.GetStructCount() == 7);
    REQUIRE(oTestParser.GetElementCount() == 12);
}