#pragma once

#include <algorithm>

namespace orestonce {
template<typename RandomAccessIterator>
RandomAccessIterator selectMaxIter2(RandomAccessIterator iter1, RandomAccessIterator iter2)
{
    if (*iter1 < *iter2)
    {
        return iter2;
    }

    return iter1;
}

template<typename RandomAccessIterator>
RandomAccessIterator selectMaxIter3(RandomAccessIterator iter1, RandomAccessIterator iter2, RandomAccessIterator iter3)
{
    if ( *iter1 < *iter2 )
    {
        return selectMaxIter2(iter2, iter3);
    }

    return selectMaxIter2(iter1, iter3);
}

template <typename RandomAccessIterator>
void Adjust(RandomAccessIterator begin, RandomAccessIterator end, RandomAccessIterator cur)
{
    auto pos = cur - begin;
    auto left = begin + pos * 2 + 1;
    auto right= begin + pos * 2 + 2;
    RandomAccessIterator maxPos ;

    if (right < end)
    {
        maxPos = selectMaxIter3(cur, left, right);
    }
    else if (left < end)
    {
        maxPos = selectMaxIter2(cur, left);
    }
    else
    {
        return;
    }

    if (maxPos != cur )
    {
        std::swap(*cur, *maxPos);
        Adjust(begin, end, maxPos);
    }
}

template <typename RandomAccessIterator>
void MakeHeap(RandomAccessIterator begin, RandomAccessIterator end)
{
    for(auto cur=end-1; cur >= begin; --cur)
    {
        Adjust(begin, end, cur);
    }
}

template <typename RandomAccessIterator>
void HeapSort(RandomAccessIterator begin, RandomAccessIterator end)
{
    MakeHeap(begin, end);

    for (RandomAccessIterator last=end-1; last > begin; --last)
    {
        std::swap(*begin, *last);
        Adjust(begin, last, begin);
    }
}

}
