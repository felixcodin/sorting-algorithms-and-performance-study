#include "../include/sorting/shaker_sort.hpp"
#include <algorithm>

template <typename T>
void shakerSort(std::vector<T> &arr)
{
    int left = 0;
    int right = arr.size() - 1;
    int k = 0;

    while (left < right)
    {
        for (int i = left; i < right; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                std::swap(arr[i], arr[i + 1]);
                k = i;
            }
        }
        right = k;

        for (int i = right; i > left; i--)
        {
            if (arr[i] < arr[i - 1])
            {
                std::swap(arr[i], arr[i - 1]);
                k = i;
            }
        }
        left = k;
    }
}

template void shakerSort<int>(std::vector<int> &);