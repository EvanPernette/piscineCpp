#include "vector.hh"

Vector& Vector::operator+=(const Vector& rhs)
{
    x += rhs.x;
    y += rhs.y;
    return *this;
}

Vector& Vector::operator-=(const Vector& rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}

Vector& Vector::operator*=(int scalar)
{
    x *= scalar;
    y *= scalar;
    return *this;
}

Vector operator+(const Vector& lhs, const Vector& rhs)
{
    Vector res = lhs;
    res += rhs;
    return res;
}

Vector operator-(const Vector& lhs, const Vector& rhs)
{
    Vector res = lhs;
    res -= rhs;
    return res;
}

Vector operator*(const Vector& lhs, int scalar)
{
    Vector res = lhs;
    res *= scalar;
    return res;
}

Vector operator*(int scalar, const Vector& rhs)
{
    return rhs * scalar;
}

int operator*(const Vector& lhs, const Vector& rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

std::ostream& operator<<(std::ostream& os, const Vector& vect)
{
    os << '{' << vect.x << "," << vect.y << '}';
    return os;
}
