#include "int-container.hh"

#include <optional>

MyIntContainer::MyIntContainer(size_t size)
    : current_size_(0)
    , max_size_(size)
    , elems_(std::make_unique<int[]>(size))
{}

void MyIntContainer::print() const
{
    std::cout << elems_[0] << " |";
    for (size_t i = 1; i < current_size_ - 1; ++i)
        std::cout << " " << elems_[i] << " |";

    std::cout << " " << elems_[current_size_ - 1] << '\n';
}

size_t MyIntContainer::get_len() const
{
    return current_size_;
}

bool MyIntContainer::add(int elem)
{
    if (current_size_ == max_size_)
    {
        return false;
    }
    elems_[current_size_] = elem;
    ++current_size_;
    return true;
}

std::optional<int> MyIntContainer::pop()
{
    if (current_size_ == 0)
    {
        return std::nullopt;
    }
    std::unique_ptr<int[]> elems_2 = std::make_unique<int[]>(current_size_);
    --current_size_;
    std::optional<int> aux = elems_[current_size_];
    for (size_t i = 0; i < current_size_; ++i)
    {
        elems_2[i] = elems_[i];
    }
    elems_ = std::move(elems_2);
    return aux;
}

std::optional<int> MyIntContainer::get(size_t position) const
{
    if (position >= current_size_)
    {
        return std::nullopt;
    }
    return elems_[position];
}

std::optional<size_t> MyIntContainer::find(int elem) const
{
    for (size_t i = 0; i < current_size_; ++i)
    {
        if (elems_[i] == elem)
        {
            return i;
        }
    }
    return std::nullopt;
}

void MyIntContainer::sort()
{
    for (size_t i = 0; i < current_size_; ++i)
    {
        for (size_t j = i + 1; j < current_size_; ++j)
        {
            if (elems_[i] > elems_[j])
            {
                int aux = elems_[i];
                elems_[i] = elems_[j];
                elems_[j] = aux;
            }
        }
    }
}

bool MyIntContainer::is_sorted() const
{
    if (current_size_ == 0)
    {
        return true;
    }
    for (size_t i = 0; i < current_size_ - 1; ++i)
    {
        if (elems_[i] > elems_[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    MyIntContainer c = MyIntContainer(10);
    for (int i = 0; i < 11; ++i)
        c.add(i);

    c.print();

    if (auto el = c.pop())
        std::cout << "element poped: " << *el << '\n';
    else
        std::cout << "Trying to pop an empty array" << '\n';

    std::cout << '\n';

    for (int i = 0; i < 10; ++i)
    {
        if (auto el = c.get(i))
            std::cout << "got element: " << *el << '\n';
        else
            std::cout << "Trying to access out of bound index: " << i << '\n';
    }

    if (auto pos = c.find(9))
        std::cout << "Position of element `9`: " << *pos << '\n';
    else
        std::cout << "Failed to find number 9" << '\n';

    return 0;
}