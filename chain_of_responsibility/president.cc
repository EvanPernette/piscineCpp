#include "president.hh"

#include <iostream>

void President::handle_request(int level)
{
    if (level > 9)
    {
        std::cout << "Nobody can handle this request" << std::endl;
    }
    else
    {
        std::cout << "President handles" << std::endl;
    }
}