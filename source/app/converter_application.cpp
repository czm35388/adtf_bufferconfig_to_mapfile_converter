#include <iostream>
#include <parser_lib.h>

int main()
{
    std::cout << "Executed 'converter_applicatoin'" << std::endl;

    cParserLib oParserLib;
    oParserLib.OpenBufferConfigFile();

    return 0;
}
