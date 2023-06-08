#include "person.hh"

Person::Person(const std::string& name, uint money)
{
    name_ = name;
    money_ = money;
}

std::vector<std::string> Person::enumerate_nfts() const
{
    std::vector<std::string> names;
    for (auto& nft : nfts_)
    {
        names.push_back(*nft);
    }
    return names;
}

void Person::add_nft(NFT nft)
{
    nfts_.push_back(std::move(nft));
}

NFT Person::remove_nft(const std::string& name)
{
    for (auto it = nfts_.begin(); it != nfts_.end(); ++it)
    {
        if (*(*it) == name)
        {
            NFT nft = std::move(*it);
            nfts_.erase(it);
            return nft;
        }
    }
    return nullptr;
}

void Person::add_money(uint money)
{
    money_ += money;
}

bool Person::remove_money(uint money)
{
    if (money <= money_)
    {
        money_ -= money;
        return true;
    }
    return false;
}

uint Person::get_money() const
{
    return money_;
}

std::string Person::get_name() const
{
    return name_;
}

std::ostream& operator<<(std::ostream& os, const Person& p)
{
    os << "Name: " << p.get_name() << "\nMoney: " << p.get_money() << "\nNFTs:";
    auto nft_names = p.enumerate_nfts();
    if (nft_names.empty())
    {}
    else
    {
        os << ' ' << nft_names[0];
        for (size_t i = 1; i < nft_names.size(); ++i)
        {
            os << " " << nft_names[i];
        }
    }
    os << '\n';
    return os;
}