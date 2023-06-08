#include "invalid-argument.hh"

InvalidArgumentException::InvalidArgumentException(const std::string& message)
{
    msg_ = message;
}

const char* InvalidArgumentException::what() const noexcept
{
    return msg_.c_str();
}