#include "forward-multiplication.hh"

#include <functional>

using lambda_type = std::function<std::function<int(int)>(int)>;
lambda_type create_lambda()
{
    return [](int x) { return [x](int y) { return x * y; }; };
}