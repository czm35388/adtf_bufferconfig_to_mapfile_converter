#pragma once

#include <iostream>

class cParserLib
{
    public:
        bool OpenBufferConfigFile(std::string strInput);

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