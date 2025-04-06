#include "../include/sorting/insertion_sort.hpp"

template <typename T>
void insertionSort(vector<T> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int j = i;
        T key = arr[i];
        while (j > 0 && key < arr[j - 1])
        {
            arr[j] = arr[j - 1];
            j -= 1;
        }
        arr[j] = key;
    }
}

template void insertionSort<int>(vector<int> &arr);