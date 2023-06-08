#include <iostream>
void my_func(int copy, int* ptr, int& ref)
{
    std::cout << "int: " << copy << " int*: " << *ptr << " int&: " << ref
    << '\n';
}
void another_func(int copy, int* ptr, const int& ref)
{
    std::cout << "int: " << copy << " int*: " << *ptr << " const int&: " << ref
    << '\n';
}
int main(){
    int one = 1;
    int two = 2;
    int three = 3;
    my_func(one, &two, three); // Works like a charm
    another_func(one, &two, 3); // Works because the value cannot be modified
}