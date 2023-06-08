#include "find-optional.hh"

#include <optional>
#include <vector>

std::optional<std::size_t> find_optional(const std::vector<int>& vect,
                                         int value)
{
    for (std::size_t i = 0; i < vect.size(); ++i)
    {
        if (vect.at(i) == value)
        {
            return i;
        }
    }
    return {};
}