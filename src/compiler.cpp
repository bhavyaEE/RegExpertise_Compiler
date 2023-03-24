#include <fstream>
#include <iostream>
#include <unistd.h>
#include "ast.hpp"

#include "cli.h"

extern FILE *yyin;

int main(int argc, char **argv)
{
    // Parse CLI arguments, to fetch the values of the source and output files.
    std::string sourcePath = "";
    std::string outputPath = "";
    if (parse_command_line_args(argc, argv, sourcePath, outputPath))
    {
        return 1;
    }

    // This configures Flex to look at sourcePath instead of reading from stdin.
    yyin = fopen(sourcePath.c_str(), "r");
    if (yyin == NULL)
    {
        perror("Could not open source file");
        return 1;
    }

    // Open the output file in truncation mode (to overwrite the contents)
    std::ofstream output;
    output.open(outputPath, std::ios::trunc);

    Context context;

    // Compile the input
    std::cout << "Compiling: " << sourcePath << std::endl;
    auto root = parseAST();
    root->visualiser(std::cout);
    root->generateRISCV(output, context, 5);
    std::cout << "Compiled to: " << outputPath << std::endl;

    output.close();
    return 0;
}
