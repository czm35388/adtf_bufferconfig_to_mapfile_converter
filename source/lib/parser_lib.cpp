#include "parser_lib.h"

bool cParserLib::OpenBufferConfigFile(std::string strInput)
{
    pugi::xml_document buffer_config_file;
    pugi::xml_parse_result result = buffer_config_file.load_file(strInput.c_str());

    m_strInputPath = strInput;

    if (!result)
    {
        std::cerr << "XML parsing failed! Error description: " << result.description() << std::endl;
        return false;
    }

    pugi::xml_node globals = buffer_config_file.child("settings");

    HandleInputNode(globals.children("input"));
    HandleOutputNode(globals.children("output"));

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
        HandleAttributes(input_node.attributes(), map_inputs_node);
        HandleBufferNode(input_node.children("buffer"), map_inputs_node);
    }

    if(m_ui8InputCount)
    {
        SaveMapFile(m_pInputMapfile, true);
    }
}

void cParserLib::HandleOutputNode(pugi::xml_object_range<pugi::xml_named_node_iterator> output_nodes)
{
    if(!m_pOutputMapfile->empty())
    {
        CreateMapFile(m_pOutputMapfile);
    }

    pugi::xml_node mapping_node = m_pOutputMapfile->last_child();
    for (const auto output_node : output_nodes)
    {
        m_ui8OutputCount +=1;
        pugi::xml_node map_outputs_node = m_pOutputMapfile->append_child("outputs");
        HandleAttributes(output_node.attributes(), map_outputs_node);
        HandleBufferNode(output_node.children("buffer"), map_outputs_node);
    }
    
    if(m_ui8OutputCount)
    {
        SaveMapFile(m_pOutputMapfile, false);
    }
}

void cParserLib::HandleBufferNode(pugi::xml_object_range<pugi::xml_named_node_iterator> buffer_nodes, pugi::xml_node map_dir_node)
{
    for (const auto buffer_node : buffer_nodes)
    {
        m_ui8BufferCount += 1;

        std::string strNode = map_dir_node.name();

        if(!strNode.compare("inputs"))
        {
            pugi::xml_node map_input_node = map_dir_node.append_child("input");
            HandleAttributes(buffer_node.attributes(), map_input_node);
            HandleStructNode(buffer_node, map_input_node);
        }
        else
        {
            pugi::xml_node map_output_node = map_dir_node.append_child("output");
            HandleAttributes(buffer_node.attributes(), map_output_node);
            HandleStructNode(buffer_node, map_output_node);
        }
    }
}

void cParserLib::HandleStructNode(pugi::xml_node buffer_node, pugi::xml_node map_dir_node)
{
    for (const auto struct_node : buffer_node.children("struct"))
    {
        m_ui8StructCount += 1;
        pugi::xml_node xml_struct_node = map_dir_node.append_child("struct");
        HandleAttributes(struct_node.attributes(), xml_struct_node);
        HandleElementNode(struct_node, xml_struct_node);
    }
}

void cParserLib::HandleElementNode(pugi::xml_node struct_node, pugi::xml_node map_struct_node)
{
    for (const auto element_node : struct_node.children("element"))
    {
        m_ui8ElementCount += 1;
        pugi::xml_node map_assignment_node = map_struct_node.append_child("assignment");
        HandleElementAttributes(element_node, map_assignment_node);
    }
}

void cParserLib::HandleAttributes(pugi::xml_object_range<pugi::xml_attribute_iterator> node_attributes, pugi::xml_node node)
{
    for (const auto node_attribute : node_attributes)
    {
        node.append_attribute(node_attribute.name()) = node_attribute.value();
    }
}

void cParserLib::HandleElementAttributes(pugi::xml_node element_node, pugi::xml_node map_assignment_node)
{
    for (const auto element_attribute : element_node.attributes())
    {
        pugi::xml_node assignment_child = map_assignment_node.append_child(element_attribute.name());
        assignment_child.text().set(element_attribute.value());
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