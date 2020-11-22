#include "parser_lib.h"

#include <iostream>
#include <filesystem>
#include <pugixml.hpp>

int cParserLib::OpenBufferConfigFile()
{
    std::cout << "Called cParserLib::OpenXMLFile()" << std::endl;

    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("c:/adtf/projects/adtf_bufferconfig_map_converter/package/bin/cc_test_daq.xml");
    
    if (result)
    {
        std::cout << "XML parsed without errors!" << std::endl << std::endl;
    }
    else
    {
        std::cout << "XML parsed with errors!" << std::endl;
        std::cout << "Error description: " << result.description() << "/n";
        std::cout << "Error offset: " << result.offset << std::endl;

        return 0;
    }

    pugi::xml_node oInputNodes = doc.first_child().child("input");
    pugi::xml_node oOutputNodes = doc.first_child().child("output");

    for(pugi::xml_node oInputNode : oInputNodes)
    {
        // Inputnodes
        std::cout << "Input Node" << std::endl << std::endl;
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
            std::cout << "Strct Count: " << nStructCount << std::endl;
            nStructCount = 0;
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}

