#pragma once

template <unsigned T>
constexpr bool is_prime()
{
    if (T <= 1)
    {
        return false;
    }
    for (unsigned i = 2; i < T; ++i)
    {
        if (T % i == 0)
        {
            return false;
        }
    }
    return true;
}