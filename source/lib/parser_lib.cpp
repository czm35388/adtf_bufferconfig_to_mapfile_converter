#include "parser_lib.h"

#include <iostream>

bool cParserLib::OpenBufferConfigFile(std::string strInput)
{
    pugi::xml_document buffer_config_file;
    pugi::xml_parse_result result = buffer_config_file.load_file(strInput.c_str());

    m_strInputPath = strInput;
    std::cout << "Input File: " << m_strInputPath.c_str() << std::endl;

    if (!result)
    {
        std::cout << "XML parsing failed!" << std::endl;
        std::cout << "Error description: " << result.description() << std::endl;
        std::cout << "Error offset: " << result.offset << std::endl;

        return false;
    }

    pugi::xml_node globals = buffer_config_file.child("settings");

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

void cParserLib::CreateMapFile(std::shared_ptr<pugi::xml_document> pMapfile)
{
    pugi::xml_node declaration_node = pMapfile->append_child(pugi::node_declaration);

    declaration_node.append_attribute("version") = "1.0";
    declaration_node.append_attribute("encoding")   = "ISO-8859-1";
    declaration_node.append_attribute("standalone") = "no";

    pugi::xml_node mapping_node = pMapfile->append_child("mapping");
    mapping_node.append_attribute("codec") = "XCP";
    mapping_node.append_attribute("version") = "2.0";
}

void cParserLib::SaveMapFile(std::shared_ptr<pugi::xml_document> pMapfile, bool bInputMapfile)
{
    std::string strMapfilePath = m_strInputPath;
    strMapfilePath.resize(strMapfilePath.length() - 4);

    if(bInputMapfile)
    {
        strMapfilePath.append("_input.map");
    }
    else
    {
        strMapfilePath.append("_output.map");
    }

    pMapfile->save_file(strMapfilePath.c_str(), PUGIXML_TEXT("  "));
}


// Handle XML node methods
void cParserLib::HandleInputNode(pugi::xml_object_range<pugi::xml_named_node_iterator> input_nodes)
{
    if(!m_pInputMapfile->empty())
    {
        CreateMapFile(m_pInputMapfile);
    }
    
    pugi::xml_node mapping_node = m_pInputMapfile->last_child();

    for (const auto input_node : input_nodes)
    {   
        m_ui8InputCount +=1;
        pugi::xml_node map_inputs_node = mapping_node.append_child("inputs");
        
        for (const auto input_attr: input_node.attributes())
        {
            std::cout << " " << input_attr.name() << "=" << input_attr.value();
        }

        std::cout << std::endl;

        HandleBufferNode(input_node.children("buffer"), map_inputs_node);

        std::cout << std::endl;
    }

    SaveMapFile(m_pInputMapfile, true);
}

void cParserLib::HandleOutputNode(pugi::xml_object_range<pugi::xml_named_node_iterator> output_nodes)
{
    for (const auto output_node : output_nodes)
    {
        m_ui8OutputCount +=1;
        pugi::xml_node map_outputs_node = m_pOutputMapfile->append_child("outputs");

        
        for (const auto output_attr: output_node.attributes())
        {
            std::cout << " " << output_attr.name() << "=" << output_attr.value();
        }

        std::cout << std::endl;
        HandleBufferNode(output_node.children("buffer"), map_outputs_node);

    }

    SaveMapFile(m_pOutputMapfile, false);

}

void cParserLib::HandleBufferNode(pugi::xml_object_range<pugi::xml_named_node_iterator> buffer_nodes, pugi::xml_node map_dir_node)
{
    for (const auto buffer_node : buffer_nodes)
    {
        m_ui8BufferCount += 1;

        if(std::string("inputs").compare(map_dir_node.value()))
        {
            pugi::xml_node map_input_node = map_dir_node.append_child("input");
            for (const auto buffer_attr : buffer_node.attributes())
            {
                map_input_node.append_attribute(buffer_attr.name()) = buffer_attr.value();
            }
        }
        else
        {
            pugi::xml_node map_output_node = map_dir_node.append_child("output");
            for (const auto buffer_attr : buffer_node.attributes())
            {
                map_output_node.append_attribute(buffer_attr.name()) = buffer_attr.value();
            }
        }

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