#pragma once

#include <set>

template <class T>
class Exist
{
public:
    bool operator()(T);

private:
    std::set<T> set_;
};

#include "exist.hxx"