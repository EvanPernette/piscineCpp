#include "list.hh"

#include <iostream>

#include "node.hh"

List::List()
{
    first_ = nullptr;
    last_ = nullptr;
    nb_elts_ = 0;
}

void List::push_front(int i)
{
    std::shared_ptr<Node> new_node = std::make_shared<Node>(i);
    if (nb_elts_ == 0)
    {
        first_ = new_node;
        last_ = new_node;
    }
    else
    {
        new_node->next_set(first_);
        first_->prev_set(new_node);
        first_ = new_node;
    }
    nb_elts_++;
}

void List::push_back(int i)
{
    std::shared_ptr<Node> new_node = std::make_shared<Node>(i);
    if (nb_elts_ == 0)
    {
        first_ = new_node;
        last_ = new_node;
    }
    else
    {
        new_node->prev_set(last_);
        last_->next_set(new_node);
        last_ = new_node;
    }
    nb_elts_++;
}

std::optional<int> List::pop_front()
{
    if (nb_elts_ <= 0)
    {
        return std::nullopt;
    }
    else
    {
        std::shared_ptr<Node> old_first = first_;
        first_ = first_->next_get();
        if (first_ != nullptr)
        {
            first_->prev_set(nullptr);
        }
        nb_elts_--;
        return old_first->val_get();
    }
}

std::optional<int> List::pop_back()
{
    if (nb_elts_ <= 0)
    {
        return std::nullopt;
    }
    else
    {
        std::shared_ptr<Node> old_last = last_;
        last_ = last_->prev_get();
        if (last_ != nullptr)
        {
            last_->next_set(nullptr);
        }
        nb_elts_--;
        return old_last->val_get();
    }
}

void List::print(std::ostream& os) const
{
    for (auto node = first_; node != nullptr; node = node->next_get())
    {
        os << node->val_get();
        if (node->next_get() != nullptr)
        {
            os << ' ';
        }
    }
}

int List::length() const
{
    return nb_elts_;
}