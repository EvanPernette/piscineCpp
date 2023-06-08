#include "closer-to.hh"

#include <iostream>

CloserTo::CloserTo(int i)
    : i_(i)
{}

bool CloserTo::operator()(const int& a, const int& b) const
{
    int dist_a = std::abs(a - i_);
    int dist_b = std::abs(b - i_);
    if (dist_a == dist_b)
    {
        return a < b;
    }
    else
    {
        return dist_a < dist_b;
    }
}