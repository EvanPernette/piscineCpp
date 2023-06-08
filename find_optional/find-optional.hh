#pragma once

#include <iostream>
#include <optional>
#include <vector>

std::optional<std::size_t> find_optional(const std::vector<int>& vect,
                                         int value);
