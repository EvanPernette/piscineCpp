#include "read-info.hh"

#include <fstream>
#include <iostream>
#include <sstream>

bool read_info(std::istream& input, DirectoryInfo& dir_info)
{
    std::string line;
    if (std::getline(input, line))
    {
        std::istringstream line_stream(line);
        if (line_stream >> dir_info.name_ && line_stream >> dir_info.size_
            && line_stream >> std::oct >> dir_info.rights_
            && line_stream >> dir_info.owner_)
        {
            char c;
            if (line_stream >> c)
            {
                return read_info(input, dir_info);
            }
            return true;
        }
    }
    return false;
}