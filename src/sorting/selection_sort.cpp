#include "../include/sorting/selection_sort.hpp"

template <typename T>
void selectionSort(vector<T> &arr)
{
    size_t n = arr.size();
    for (size_t i = 0; i < n - 1; i++)
    {
        size_t minIndex = i;
        for (size_t j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swap(arr[minIndex], arr[i]);
        }
    }
}

template void selectionSort<int>(vector<int> &arr);