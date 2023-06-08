#include "stdin-to-file.hh"

#include <fstream>
#include <iostream>
#include <string>

void stdin_to_file()
{
    std::fstream file("file.out", std::ios::out);
    if (file.is_open())
    {
        std::string token;
        while (std::cin >> token)
        {
            file << token << "\n";
        }
        file.close();
    }
    else
    {
        std::cerr << "Unable to open file.out" << std::endl;
    }
}