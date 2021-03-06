#pragma once

#include <iostream>
#include <memory>

#include "../../3rdparty/pugixml-1.10/src/pugixml.hpp"

class cParserLib
{
    public:
        bool OpenBufferConfigFile(std::string strInput);
        void CreateMapFile(std::shared_ptr<pugi::xml_document> pMapfile);
        void SaveMapFile(std::shared_ptr<pugi::xml_document> pMapfile, bool bInputMapfile);

        // Handle XML node methods
        void HandleInputNode(pugi::xml_object_range<pugi::xml_named_node_iterator> input_nodes);
        void HandleOutputNode(pugi::xml_object_range<pugi::xml_named_node_iterator> output_nodes);
        void HandleBufferNode(pugi::xml_object_range<pugi::xml_named_node_iterator> buffer_nodes, pugi::xml_node map_dir_node);
        void HandleStructNode(pugi::xml_node buffer_node, pugi::xml_node map_dir_node);
        void HandleElementNode(pugi::xml_node struct_node, pugi::xml_node map_struct_node);
        void HandleAttributes(pugi::xml_object_range<pugi::xml_attribute_iterator> node_attributes, pugi::xml_node node);
        void HandleElementAttributes(pugi::xml_node element_node, pugi::xml_node map_assignment_node);

        // Getter methods
        uint8_t GetInputCount();
        uint8_t GetOutputCount();
        uint8_t GetBufferCount();
        uint8_t GetStructCount();
        uint8_t GetElementCount();

    private:
        uint8_t m_ui8InputCount = 0;
        uint8_t m_ui8OutputCount = 0;
        uint8_t m_ui8BufferCount = 0;
        uint8_t m_ui8StructCount = 0;
        uint8_t m_ui8ElementCount = 0;

        std::string m_strInputPath = "";

        std::shared_ptr<pugi::xml_document> m_pInputMapfile = std::make_shared<pugi::xml_document>();
        std::shared_ptr<pugi::xml_document> m_pOutputMapfile = std::make_shared<pugi::xml_document>();
};