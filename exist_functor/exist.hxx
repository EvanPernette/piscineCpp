#pragma once

#include "exist.hh"

template <class T>
bool Exist<T>::operator()(T t)
{
    if (set_.find(t) == set_.end())
    {
        set_.insert(t);
        return false;
    }
    return true;
}