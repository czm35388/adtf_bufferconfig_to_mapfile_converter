#include <iostream>
#include <parser_lib.h>
#include "../../3rdparty/Clara/clara.hpp"

int main ( int argc, char** argv )
{

    bool bShowHelp = false;
    std::string strInputFile;
    std::string strOutputFile;

    auto cli = clara::detail::Help(bShowHelp)
             | clara::detail::Opt( strInputFile, "InputFile" )["-i"]["--input"]("Path to the input xml file")
             | clara::detail::Opt( strOutputFile, "OutputFile" )["-o"]["--output"]("Path to the output map file");
    
    auto result = cli.parse( clara::detail::Args( argc, argv ) );
    
    if( !result )
    {
        std::cerr << "Error in command line: " << result.errorMessage() << std::endl;
        exit(1);
    }

    if ( bShowHelp )
    {
    	std::cerr << cli << std::endl;
    }

    cParserLib oParserLib;
    oParserLib.OpenBufferConfigFile(strInputFile);

    return 0;
}
