#include "../include/sorting/binary_insertion_sort.hpp"
#include <iostream>

template <typename T>
int binarySearch(const vector<T> &arr, int left, int right, T key)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (key < arr[mid])
        {
            right = mid - 1;
        }
        else if (key > arr[mid])
        {
            left = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return left;
}

template <typename T>
void binaryInsertionSort(vector<T> &arr)
{
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        T key = arr[i];
        int pos = binarySearch(arr, 0, i - 1, key);
        int j = i;

        while (j > pos)
        {
            arr[j] = arr[j - 1];
            j--;
        }

        arr[pos] = key;
    }
}

template void binaryInsertionSort<int>(vector<int>&);