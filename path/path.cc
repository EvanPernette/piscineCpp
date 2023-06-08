#include "path.hh"

#include <iostream>
#include <vector>

std::string Path::to_string() const
{
    std::string result;

    for (const auto& element : path_)
    {
        result += element;
        if (!final_)
        {
            result += '/';
        }
    }

    if (path_.empty())
    {
        result += '/';
    }

    return result;
}

Path& Path::join(const std::string& tail, bool is_file)
{
    if (final_)
    {
        return *this;
    }

    path_.push_back(tail);

    final_ = is_file;

    if (!is_file)
    {
        path_.push_back("/");
    }

    return *this;
}