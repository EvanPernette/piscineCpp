#include "address-book.hh"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>

bool AddressBook::add(const std::string& full_name, const std::string& email,
                      const std::string& number)
{
    if (full_name.empty() || full_name.find(' ') == std::string::npos)
    {
        return false;
    }
    if (email.empty() || email.find('@') == std::string::npos)
    {
        return false;
    }
    if (number.empty()
        || (!std::all_of(number.begin(), number.end(), ::isdigit)))
    {
        return false;
    }
    ContactDetails contact = ContactDetails(number, email);
    contacts.insert(std::pair<std::string, ContactDetails>(full_name, contact));
    return true;
}

std::vector<ContactDetails> AddressBook::find(const std::string& full_name)
{
    std::vector<ContactDetails> v;
    for (auto it = contacts.begin(); it != contacts.end(); it++)
    {
        if (it->first == full_name)
        {
            v.push_back(it->second);
        }
    }
    return v;
}

std::size_t AddressBook::count(const std::string& full_name)
{
    std::size_t count = 0;
    for (auto it = contacts.begin(); it != contacts.end(); it++)
    {
        if (it->first == full_name)
        {
            count++;
        }
    }
    return count;
}

bool AddressBook::remove(const std::string& full_name, std::size_t index)
{
    std::size_t count = 0;
    for (auto it = contacts.begin(); it != contacts.end(); it++)
    {
        if (it->first == full_name)
        {
            if (count == index)
            {
                contacts.erase(it);
                return true;
            }
            count++;
        }
    }
    return false;
}

void AddressBook::remove_all(const std::string& full_name)
{
    for (auto it = contacts.begin(); it != contacts.end(); it++)
    {
        if (it->first == full_name)
        {
            contacts.erase(it);
        }
    }
}

std::ostream& operator<<(std::ostream& os, const AddressBook& b)
{
    os << b.contacts.size() << " contact(s) in the address book." << std::endl;
    for (auto it = b.contacts.begin(); it != b.contacts.end(); it++)
    {
        os << "- " << it->first << ": " << it->second.number << ", "
           << it->second.email << std::endl;
    }
    return os;
}