#include <parser_lib.h>

#define CATCH_CONFIG_MAIN
#include "../../3rdparty/Catch2/catch.hpp"

TEST_CASE("Open XML File", "[open_xml_file]") 
{
    cParserLib oTestParser;
    REQUIRE(oTestParser.OpenBufferConfigFile("test") == 0);
}