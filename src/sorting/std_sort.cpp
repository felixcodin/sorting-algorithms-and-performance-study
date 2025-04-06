#include "../include/sorting/std_sort.hpp"

template <typename T>
void stdSort(std::vector<T> &arr)
{
    std::sort(arr.begin(), arr.end());
}

template void stdSort<int>(std::vector<int> &arr);