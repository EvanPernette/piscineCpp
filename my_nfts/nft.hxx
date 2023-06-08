#pragma once

#include "nft.hh"

using NFT = std::unique_ptr<std::string>;

inline NFT create_empty_nft()
{
    NFT t = std::make_unique<std::string>();
    t = nullptr;
    return t;
}

inline NFT create_nft(const std::string& name)
{
    NFT t = std::make_unique<std::string>(name);
    return t;
}