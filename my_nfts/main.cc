#include <iostream>

#include "auction.hh"

int main()
{
    // Create some people with money and NFTs.
    Person alice("Alice", 100);
    Person bob("Bob", 70);
    alice.add_nft(create_nft("Mona Lisa"));
    bob.add_nft(create_nft("The Starry Night"));

    // Start an auction.
    Auction auction(alice, create_nft("Mona Lisa"), 50);

    // Alice tries to bid with too little money.
    if (auction.bid(alice, 60))
    {
        std::cout << "Alice won the auction for $40\n";
    }
    else
    {
        std::cout << "Alice failed to bid for $40\n";
    }

    // Bob bids and wins the auction.
    if (auction.bid(bob, 70))
    {
        std::cout << "Bob won the auction for $70\n";
    }
    else
    {
        std::cout << "Bob failed to bid for $70\n";
    }

    // Print the results.
    std::cout << "Highest bid: $" << auction.get_highest_bid() << "\n";
    std::cout << "NFT name: " << auction.get_nft_name() << "\n";
    std::cout << alice << "\n";
    std::cout << bob << "\n";

    return 0;
}