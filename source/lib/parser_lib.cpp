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

    pugi::xml_node globals = doc.child("settings");

    for (pugi::xml_node input: globals.children("input"))
    {
        m_ui8InputCount += 1;

        for (pugi::xml_attribute input_attr: input.attributes())
        {
            std::cout << " " << input_attr.name() << "=" << input_attr.value();
        }

        for (pugi::xml_node buffer: input.children("buffer"))
        {
            m_ui8BufferCount += 1;

            for (pugi::xml_attribute buffer_attr: buffer.attributes())
            {
                std::cout << " " << buffer_attr.name() << "=" << buffer_attr.value();
            }

                for (pugi::xml_node struct_node: buffer.children("struct"))
                {
                    m_ui8StructCount += 1;

                    for (pugi::xml_attribute struct_attr: struct_node.attributes())
                    {
                        std::cout << " " << struct_attr.name() << "=" << struct_attr.value();
                    }

                        for (pugi::xml_node element_node: struct_node.children("element"))
                        {
                            m_ui8ElementCount += 1;

                            for (pugi::xml_attribute element_attr: element_node.attributes())
                            {
                                std::cout << " " << element_attr.name() << "=" << element_attr.value();
                            }   
                        }
                }
        }
        std::cout << std::endl;
    }

    for (pugi::xml_node output: globals.children("output"))
    {
        m_ui8OutputCount +=1;
        
        for (pugi::xml_attribute output_attr: output.attributes())
        {
            std::cout << " " << output_attr.name() << "=" << output_attr.value();
        }

        for (pugi::xml_node buffer: output.children("buffer"))
        {
            m_ui8BufferCount += 1;

            for (pugi::xml_attribute buffer_attr: buffer.attributes())
            {
                std::cout << " " << buffer_attr.name() << "=" << buffer_attr.value();
            }

            for (pugi::xml_node struct_node: buffer.children("struct"))
            {
                m_ui8StructCount += 1;

                for (pugi::xml_attribute struct_attr: struct_node.attributes())
                {
                    std::cout << " " << struct_attr.name() << "=" << struct_attr.value();
                }

                for (pugi::xml_node element_node: struct_node.children("element"))
                {
                    m_ui8ElementCount += 1;

                    for (pugi::xml_attribute element_attr: element_node.attributes())
                    {
                        std::cout << " " << element_attr.name() << "=" << element_attr.value();
                    }   
                }
            }
        }

        std::cout << std::endl;
    }
    return true;
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