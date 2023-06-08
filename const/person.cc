#include "person.hh"

#include <iostream>
#include <string>

Person::Person(const std::string& name1, unsigned int age1)
{
    name_ = name1;
    age_ = age1;
}

std::string Person::name_get() const
{
    return name_;
}

unsigned int Person::age_get() const
{
    return age_;
}

void Person::name_set(const std::string& name1)
{
    name_ = name1;
}

void Person::age_set(unsigned int age1)
{
    age_ = age1;
}
