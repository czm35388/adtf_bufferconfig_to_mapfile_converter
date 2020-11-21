#include <iostream>
#include "parser_lib.h"

void cParserLib::OpenBufferConfigFile()
{
    std::cout << "Called cParserLib::OpenXMLFile()" << std::endl;

    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("tree.xml");
    std::cout << "Load result: " << result.description() << ", mesh name: " << doc.child("mesh").attribute("name").value() << std::endl;
}