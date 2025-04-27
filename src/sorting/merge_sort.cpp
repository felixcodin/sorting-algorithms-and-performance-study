#include "../include/sorting/merge_sort.hpp"
#include <algorithm>

template <typename T>
void merge(std::vector<T> &arr, int left, int right)
{
    int mid = left + (right - left) / 2;
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    std::vector<T> leftVector(leftSize);
    std::vector<T> rightVector(rightSize);

    for (int i = 0; i < leftSize; ++i)
        leftVector[i] = arr[left + i];
    for (int i = 0; i < rightSize; ++i)
        leftVector[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < leftSize && j < rightSize)
    {
        if (leftVector[i] <= rightVector[j])
        {
            arr[k] = leftVector[i];
            ++i;
        }
        else
        {
            arr[k] = rightVector[j];
            ++j;
        }
        ++k;
    }

    while (i < leftSize)
    {
        arr[k] = leftVector[i];
        ++i;
        ++k;
    }

    while (j < rightSize)
    {
        arr[k] = rightVector[j];
        ++j;
        ++k;
    }
}

template <typename T>
void mergeSortHelper(std::vector<T> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSortHelper(arr, left, mid);
        mergeSortHelper(arr, mid + 1, right);

        merge(arr, left, right);
    }
}

template <typename T>
void mergeSort(std::vector<T> &arr)
{
    mergeSortHelper(arr, 0, arr.size() - 1);
}

template void mergeSort<int>(std::vector<int> &);