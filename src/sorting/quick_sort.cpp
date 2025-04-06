#include "../include/sorting/quick_sort.hpp"
#include "../include/utils/data_generator.hpp"
#include <algorithm>

template <typename T>
static int partition(std::vector<T> &arr, int left, int right)
{
    int pivotIndex = generateRandomNumber(left, right);

    std::swap(arr[pivotIndex], arr[right]);
    int i = left - 1;
    T pivot = arr[right];
    for (int j = left; j < right; j++)
    {
        if (arr[j] < pivot)
        {
            i += 1;
            std::swap(arr[i], arr[j]);
        }
    }
    
    std::swap(arr[right], arr[i + 1]);
    return i + 1;
}

template <typename T>
static void quickSortHelper(std::vector<T> &arr, int left, int right)
{
    if (left < right)
    {
        int pi = partition(arr, left, right);

        quickSortHelper(arr, left, pi - 1);
        quickSortHelper(arr, pi + 1, right);
    }
}

template <typename T>
void quickSort(std::vector<T> &arr)
{
    quickSortHelper(arr, 0, arr.size() - 1);
}

template void quickSort<int>(std::vector<int> &);