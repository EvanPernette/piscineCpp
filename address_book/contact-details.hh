#pragma once

#include <iostream>
#include <string>

struct ContactDetails
{
    ContactDetails(const std::string& telephone_number,
                   const std::string& personal_email);
    friend std::ostream& operator<<(std::ostream& os,
                                    const ContactDetails& contact);
    std::string number;
    std::string email;
};