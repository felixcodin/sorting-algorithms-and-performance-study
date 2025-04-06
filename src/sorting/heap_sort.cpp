#include "../include/sorting/heap_sort.hpp"
#include <algorithm>

template <typename T>
void heapify(std::vector<T> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        std::swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

template <typename T>
void heapSort(std::vector<T> &arr)
{
    int n = arr.size();

    for (int i = n/2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        std::swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}

template void heapSort<int>(std::vector<int> &);