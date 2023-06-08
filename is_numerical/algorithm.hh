#pragma once

#include <iostream>

#include "enable-if.hh"
#include "is-numerical.hh"

template <typename T>
typename enable_if<is_numerical<T>::value, T>::type algorithm(T t)
{
    return t;
}