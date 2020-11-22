#include "parser_lib.h"

#include <iostream>
#include <pugixml.hpp>

void cParserLib::OpenBufferConfigFile()
{
    std::cout << "Called cParserLib::OpenXMLFile()" << std::endl;

    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("c:/adtf/projects/adtf_bufferconfig_map_converter/package/bin/tree.xml");
    std::cout << "Load result: " << result.description() << ", root type: " << doc.child("root").attribute("type").value() << std::endl;
}