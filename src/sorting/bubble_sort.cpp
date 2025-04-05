#include "../include/sorting/bubble_sort.hpp"
#include <algorithm>

template <typename T>
void bubbleSort(std::vector<T> &arr)
{
    size_t n = arr.size();

    for (size_t i = 0; i < n - 2; i++)
    {
        for (size_t j = n - 1; j >= i + 1; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                std::swap(arr[j], arr[j - 1]);
            }
        }
    }
}

template void bubbleSort<int>(std::vector<int> &);