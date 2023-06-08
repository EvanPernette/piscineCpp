#pragma once

#include <iostream>
#include <vector>

#include "path.hh"

class UnixPath : public Path
{
public:
    UnixPath() = default;
    ~UnixPath() = default;

    std::string to_string() const override;

private:
    std::string root_;
};
