#include <iostream>
#include <parser_lib.h>

int main()
{
    std::cout << "Executed 'converter_application'" << std::endl;

    cParserLib oParserLib;
    oParserLib.OpenBufferConfigFile();

    return 0;
}
