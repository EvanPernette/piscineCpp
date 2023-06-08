#pragma once

#include <iostream>

class Person
{
public:
    Person(const std::string& name1, unsigned int age1);

public:
    std::string name_get() const;

public:
    unsigned int age_get() const;

public:
    void name_set(const std::string& name1);

public:
    void age_set(unsigned int age1);
    std::string name_;
    unsigned int age_;
};