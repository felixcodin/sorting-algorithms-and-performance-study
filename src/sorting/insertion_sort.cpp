#include "../include/sorting/insertion_sort.hpp"

template <typename T>
void insertionSort(vector<T> &arr)
{
    size_t n = arr.size();
    for (size_t i = 1; i < n; i++)
    {
        size_t j = i;
        size_t key = arr[i];
        while (j > 0 && key < arr[j])
        {
            arr[j] = arr[j - 1];
            j -= 1;
        }
        arr[j] = key;
    }
}