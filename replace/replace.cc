#include "replace.hh"

#include <fstream>
#include <iostream>
#include <string>

void replace(const std::string& input_filename,
             const std::string& output_filename, const std::string& src_token,
             const std::string& dst_token)
{
    std::fstream file1(input_filename, std::ios::in);
    if (!file1)
    {
        std::cerr << "Cannot open input file" << std::endl;
        return;
    }

    std::fstream file2(output_filename, std::ios::out);
    if (!file2)
    {
        std::cerr << "Cannot write output file" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file1, line))
    {
        std::size_t pos = 0;
        while ((pos = line.find(src_token, pos)) != std::string::npos)
        {
            line.replace(pos, src_token.length(), dst_token);
            pos += dst_token.length();
        }
        file2 << line << std::endl;
    }

    file1.close();
    file2.close();
}