#include "contact-details.hh"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>

ContactDetails::ContactDetails(const std::string& telephone_number,
                               const std::string& personal_email)
{
    if (telephone_number.empty()
        || (!std::all_of(telephone_number.begin(), telephone_number.end(),
                         ::isdigit)))
    {
        throw std::invalid_argument("Incorrect number.");
    }
    if (personal_email.empty() || personal_email.find('@') == std::string::npos)
    {
        throw std::invalid_argument("Incorrect email.");
    }
    number = telephone_number;
    email = personal_email;
}

std::ostream& operator<<(std::ostream& os, const ContactDetails& contact)
{
    os << contact.number;
    os << ", " << contact.email << '\n';
    return os;
}