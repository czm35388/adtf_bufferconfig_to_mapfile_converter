#pragma once

#include <iostream>

#include "../../3rdparty/pugixml-1.10/src/pugixml.hpp"

class cParserLib
{
    public:
        bool OpenBufferConfigFile(std::string strInput);

        // Handle XML node methods
        void HandleInputNode(pugi::xml_object_range<pugi::xml_named_node_iterator> input_nodes);
        void HandleOutputNode(pugi::xml_object_range<pugi::xml_named_node_iterator> output_nodes);
        void HandleBufferNode(pugi::xml_object_range<pugi::xml_named_node_iterator> buffer_nodes);
        void HandleStructNode(pugi::xml_object_range<pugi::xml_named_node_iterator> struct_nodes);
        void HandleElementNode(pugi::xml_object_range<pugi::xml_named_node_iterator> element_nodes);

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
};