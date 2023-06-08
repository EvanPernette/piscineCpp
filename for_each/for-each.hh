#pragma once

template <class type, class function>
function my_foreach(type first, type last, function f)
{
    for (auto it = first; it != last; ++it)
    {
        f(*it);
    }
    return f;
}