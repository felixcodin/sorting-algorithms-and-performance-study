#include "../include/sorting/merge_sort.hpp"
#include <algorithm>

static int nextGap(int gap)
{
    if (gap <= 1)
    {
        return 0;
    }
    return (gap / 2) + (gap % 2);
}

template <typename T>
void merge(std::vector<T> &arr, int left, int right)
{
    int gap = right - left + 1;

    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap))
    {
        for (int i = left; i + gap <= right; i++)
        {
            if (arr[i] > arr[i + gap])
            {
                std::swap(arr[i], arr[i + gap]);
            }
        }
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