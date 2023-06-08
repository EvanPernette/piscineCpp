#pragma once

template <typename T>
struct is_numerical
{
    static const bool value = false;
};

template <>
struct is_numerical<int>
{
    static const bool value = true;
};

template <>
struct is_numerical<float>
{
    static const bool value = true;
};

template <>
struct is_numerical<char>
{
    static const bool value = true;
};

template <>
struct is_numerical<double>
{
    static const bool value = true;
};

template <>
struct is_numerical<long>
{
    static const bool value = true;
};

template <>
struct is_numerical<long long>
{
    static const bool value = true;
};

template <>
struct is_numerical<unsigned int>
{
    static const bool value = true;
};

template <>
struct is_numerical<unsigned long>
{
    static const bool value = true;
};

template <>
struct is_numerical<unsigned long long>
{
    static const bool value = true;
};

template <>
struct is_numerical<short>
{
    static const bool value = true;
};

template <>
struct is_numerical<unsigned short>
{
    static const bool value = true;
};

template <>
struct is_numerical<bool>
{
    static const bool value = true;
};