#include <string>
#include <fstream>
#include <iostream>

class Point
{
    int x_ = 0;
    int y_ = 0;

    public: void display() const
    {
        std::cout << "x: " << x_ << " y: " << y_ << '\n';
    }

    public : void move (int x , int y)
    {
        x_ += x;
        y_ += y;
    }
};

int main()
{
    Point a;
    const Point c;
    // The following instructions are correct:
    a.display();
    c.display();
    // However, this one is rejected by the compiler:
}