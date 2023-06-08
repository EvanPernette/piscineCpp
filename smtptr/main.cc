#include "shared-pointer.hh"

int main()
{
    SharedPointer<int> p1(new int(42));
    std::cout << "*p1 = " << *p1 << std::endl; // Output: *p1 = 42

    p1.reset(new int(24));
    std::cout << "*p1 = " << *p1 << std::endl; // Output: *p1 = 24

    return 0;
}