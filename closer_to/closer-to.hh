#pragma once

#include <algorithm>

struct CloserTo
{
    CloserTo(int i);

    bool operator()(const int& a, const int& b) const;

private:
    int i_;
};
