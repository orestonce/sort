#include <iostream>
#include <vector>
#include <assert.h>
#include "heapsort.hpp"

void Test_HeapSort();

int main()
{
    Test_HeapSort();

    return 0;
}


void Test_HeapSort()
{
    std::vector<int> arr = {4, 7, 2, 8, 9, 6, 1, 4, 8, 3};
    auto arrcopy = arr;
    std::sort(arrcopy.begin(), arrcopy.end());

    orestonce::HeapSort( arr.begin(), arr.end() );
    assert(arr == arrcopy );
}
