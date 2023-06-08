#include "auction.hh"

Auction::Auction(Person& organizer, NFT nft, uint initial_bid)
    : organizer_(organizer)
    , nft_(std::move(nft))
    , highest_bidder_(nullptr)
    , highest_bid_(initial_bid)
{
    if (nft_ == nullptr)
    {
        throw std::invalid_argument("bad nft");
    }
}

Auction::~Auction()
{
    if (highest_bidder_ != nullptr)
    {
        organizer_.add_money(highest_bid_);
        highest_bidder_->add_nft(std::move(nft_));
    }
    else
    {
        organizer_.add_nft(std::move(nft_));
    }
}

bool Auction::bid(Person& person, uint money)
{
    if (person.get_money() < money || money <= 0)
    {
        return false;
    }

    if (highest_bidder_ == nullptr)
    {
        if (money >= highest_bid_)
        {
            person.remove_money(money);
            highest_bidder_ = &person;
            highest_bid_ = money;
            return true;
        }
    }
    else if (money > highest_bid_)
    {
        highest_bidder_->add_money(highest_bid_);
        person.remove_money(money);
        highest_bidder_ = &person;
        highest_bid_ = money;
        return true;
    }

    return false;
}

std::string Auction::get_nft_name() const
{
    return *nft_;
}

uint Auction::get_highest_bid() const
{
    return highest_bid_;
}
