#include "../include/sorting/counting_sort.hpp"
#include <stdexcept>

template <typename T>
static T getMax(const std::vector<T> &arr)
{
    T mx = arr[0];
    for (size_t i = 1; i < arr.size(); i++)
    {
        if (arr[i] > mx)
        {
            mx = arr[i];
        }
    }
    return mx;
}

template <typename T>
void countingSort(std::vector<T> &arr)
{
    size_t n = arr.size();
    if (n == 0)
    {
        return ;
    }

    T mx = getMax(arr);

    std::vector<T> count(mx + 1, 0);

    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            throw std::invalid_argument("Counting Sort only works with non-negative integers.");
        }
        count[arr[i]]++;
    }

    for (size_t i = 0, j = 0; i < n && j <= mx; j++)
    {
        while (count[j] > 0)
        {
            count[j]--;
            arr[i++] = j;
        }
    }
}

template void countingSort<int>(std::vector<int> &);