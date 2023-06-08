#include "unix-path.hh"

std::string UnixPath::to_string() const
{
    std::string res;
    res += "/";
    for (auto it = path_.begin(); it != path_.end(); ++it)
    {
        res += *it;
    }
    return res;
}