#include "parser_lib.h"

#include <iostream>
#include <unistd.h>
#include "pugixml.hpp"

bool cParserLib::OpenBufferConfigFile(std::string strInput)
{
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(strInput.c_str());


    if (!result)
    {
        std::cout << "XML parsing failed!" << std::endl;
        std::cout << "Error description: " << result.description() << std::endl;
        std::cout << "Error offset: " << result.offset << std::endl;

        return false;
    }

    pugi::xml_node oInputNodes = doc.first_child().child("input");
    pugi::xml_node oOutputNodes = doc.first_child().child("output");

    for(pugi::xml_node oInputNode : oInputNodes)
    {
        // Inputnodes
        // Buffernodes
        pugi::xml_node oInputBufferNodes = doc.child("settings").child("input");
        std::cout << "Input Node:" << oInputBufferNodes.child("input").attribute("name").value() << std::endl;
        for(pugi::xml_node oInputBufferNode : oInputBufferNodes)
        {
            std::cout << "Buffer Node:" << std::endl;
            for (pugi::xml_attribute attr: oInputBufferNode.attributes())
            {
                std::cout << attr.name() << "=" << attr.value() << std::endl;
            }
            std::cout << std::endl;

            // Structnodes
            int nStructCount = 0;   
            pugi::xml_node oStructNodes = doc.child("settings").child("input").child("buffer");
            for(pugi::xml_node oStructNode : oStructNodes)
            {
                nStructCount += 1;
                std::cout << "Struct Node" << std::endl;
                for (pugi::xml_attribute attr: oStructNode.attributes())
                {
                    std::cout << attr.name() << "=" << attr.value() << std::endl;
                }
                std::cout << std::endl;
                
                // Elementnodes
                int nElementCount = 0;
                pugi::xml_node oElementNodes = doc.child("settings").child("input").child("buffer").child("struct");
                for(pugi::xml_node oElementNode : oElementNodes)
                {
                    nElementCount += 1;
                    std::cout << "Element Node" << std::endl;
                    for (pugi::xml_attribute attr: oElementNode.attributes())
                    {
                        std::cout << attr.name() << "=" << attr.value() << std::endl;
                    }
                    std::cout << std::endl;
                }
                std::cout << "Element Count: " << nElementCount << std::endl;
                nElementCount = 0;
                std::cout << std::endl;
            }
            std::cout << "Struct Count: " << nStructCount << std::endl;
            nStructCount = 0;
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for(pugi::xml_node oOutput : oOutputNodes)
    {
        // Inputnodes
        std::cout << "Output Node" << std::endl << std::endl;
        // Buffernodes
        pugi::xml_node oInputBufferNodes = doc.child("settings").child("input");
        for(pugi::xml_node oInputBufferNode : oInputBufferNodes)
        {
            std::cout << "Buffer Node:" << std::endl;
            for (pugi::xml_attribute attr: oInputBufferNode.attributes())
            {
                std::cout << attr.name() << "=" << attr.value() << std::endl;
            }
            std::cout << std::endl;

            // Structnodes
            int nStructCount = 0;
            pugi::xml_node oStructNodes = doc.child("settings").child("input").child("buffer");
            for(pugi::xml_node oStructNode : oStructNodes)
            {
                nStructCount += 1;
                std::cout << "Struct Node" << std::endl;
                for (pugi::xml_attribute attr: oStructNode.attributes())
                {
                    std::cout << attr.name() << "=" << attr.value() << std::endl;
                }
                std::cout << std::endl;
                
                // Elementnodes
                int nElementCount = 0;
                pugi::xml_node oElementNodes = doc.child("settings").child("input").child("buffer").child("struct");
                for(pugi::xml_node oElementNode : oElementNodes)
                {
                    nElementCount += 1;
                    std::cout << "Element Node" << std::endl;
                    for (pugi::xml_attribute attr: oElementNode.attributes())
                    {
                        std::cout << attr.name() << "=" << attr.value() << std::endl;
                    }
                    std::cout << std::endl;
                }
                std::cout << "Element Count: " << nElementCount << std::endl;
                nElementCount = 0;
                std::cout << std::endl;
            }
            std::cout << "Struct Count: " << nStructCount << std::endl;
            nStructCount = 0;
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return true;
}

