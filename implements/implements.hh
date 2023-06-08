#pragma once

template <typename T, typename U = T>
concept impl_basic_op = requires(T a, U b)
{
    +a;
    -a;
    a + b;
    a - b;
    a* b;
    a / b;
};

template <typename T, typename U = T>
concept impl_modulo = requires(T a, U b)
{
    a % b;
};

template <typename T, typename U = T>
concept impl_bitwise_op = requires(T a, U b)
{
    ~a;
    a& b;
    a | b;
    a ^ b;
    a << b;
    a >> b;
};

template <typename T, typename U = T>
concept impl_arith_op = requires(T a, U b)
{
    requires impl_basic_op<T, U>;
    requires impl_modulo<T, U>;
    requires impl_bitwise_op<T, U>;
};