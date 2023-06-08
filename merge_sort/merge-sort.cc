#include "merge-sort.hh"

#include <algorithm>
#include <vector>

using iterator_type = std::vector<int>::iterator;

void merge_sort(iterator_type begin, iterator_type end)
{
    if (end - begin <= 1)
    {
        return;
    }
    iterator_type mid = begin + (end - begin) / 2;
    merge_sort(begin, mid);
    merge_sort(mid, end);
    std::inplace_merge(begin, mid, end);
}