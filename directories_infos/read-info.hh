#pragma once

#include <fstream>

#include "directory-info.hh"

bool read_info(std::istream& input, DirectoryInfo& dir_info);
