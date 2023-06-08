#include "handler.hh"

#include <iostream>

Handler::Handler(Handler* next)
{
    next_ = next;
}

void Handler::set_successor(Handler* successor)
{
    next_ = successor;
}

void Handler::forward_request(int level)
{
    if (next_ != nullptr)
    {
        next_->handle_request(level);
    }
    else
    {
        std::cout << "Nobody can handle this request" << std::endl;
    }
}
