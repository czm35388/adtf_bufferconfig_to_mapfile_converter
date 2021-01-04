#include "parser_lib.h"

#include <iostream>

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

    pugi::xml_node globals = doc.child("settings");

    HandleInputNode(globals.children("input"));
    HandleOutputNode(globals.children("output"));

    std::cout << std::endl << "Parsing finished!" << std::endl << std::endl;

    std::cout << "This bufferconfig file contains: " << std::endl;
    std::cout << "Input nodes:   " << m_ui8InputCount << std::endl;
    std::cout << "Output nodes:  " << m_ui8OutputCount << std::endl;
    std::cout << "Buffer nodes:  " << m_ui8BufferCount << std::endl;
    std::cout << "Struct nodes:  " << m_ui8StructCount << std::endl;
    std::cout << "Element nodes: " << m_ui8ElementCount << std::endl;

    return true;
}

// Handle XML node methods
void cParserLib::HandleInputNode(pugi::xml_object_range<pugi::xml_named_node_iterator> input_nodes)
{
    for (const auto input_node : input_nodes)
    {
        m_ui8InputCount +=1;
        
        for (const auto input_attr: input_node.attributes())
        {
            std::cout << " " << input_attr.name() << "=" << input_attr.value();
        }

        std::cout << std::endl;

        HandleBufferNode(input_node.children("buffer"));

        std::cout << std::endl;
    }
}

void cParserLib::HandleOutputNode(pugi::xml_object_range<pugi::xml_named_node_iterator> output_nodes)
{
    for (const auto output_node : output_nodes)
    {
        m_ui8OutputCount +=1;
        
        for (const auto output_attr: output_node.attributes())
        {
            std::cout << " " << output_attr.name() << "=" << output_attr.value();
        }

        std::cout << std::endl;

        HandleBufferNode(output_node.children("buffer"));

        std::cout << std::endl;
    }
}

void cParserLib::HandleBufferNode(pugi::xml_object_range<pugi::xml_named_node_iterator> buffer_nodes)
{
    for (const auto buffer_node : buffer_nodes)
    {
        m_ui8BufferCount += 1;

        for (const auto buffer_attr : buffer_node.attributes())
        {
            std::cout << " " << buffer_attr.name() << "=" << buffer_attr.value();
        }

        std::cout << std::endl;

        HandleStructNode(buffer_node.children("struct"));

    }
}

void cParserLib::HandleStructNode(pugi::xml_object_range<pugi::xml_named_node_iterator> struct_nodes)
{
    for (const auto struct_node : struct_nodes)
    {
        m_ui8StructCount += 1;

        for (const auto struct_attr: struct_node.attributes())
        {
            std::cout << " " << struct_attr.name() << "=" << struct_attr.value();
        }

        std::cout << std::endl;
        
        HandleElementNode(struct_node.children("element"));
    }
}

void cParserLib::HandleElementNode(pugi::xml_object_range<pugi::xml_named_node_iterator> element_nodes)
{
    for (const auto element_node : element_nodes)
    {
        m_ui8ElementCount += 1;

        for (const auto element_attr: element_node.attributes())
        {
            std::cout << " " << element_attr.name() << "=" << element_attr.value();
        }   

        std::cout << std::endl;
    }
}

// Getter methods
uint8_t cParserLib::GetInputCount()
{
    return m_ui8InputCount;
}

uint8_t cParserLib::GetOutputCount()
{
    return m_ui8OutputCount;
}

uint8_t cParserLib::GetBufferCount()
{
    return m_ui8BufferCount;
}

uint8_t cParserLib::GetStructCount()
{
    return m_ui8StructCount;
}

uint8_t cParserLib::GetElementCount()
{
    return m_ui8ElementCount;
}