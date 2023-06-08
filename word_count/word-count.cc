#include "word-count.hh"

#include <fstream>
#include <iostream>
#include <string>

ssize_t word_count(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        return -1;
    }

    std::string word;
    ssize_t count = 0;
    while (file >> word)
    {
        count++;
    }

    return count;
}