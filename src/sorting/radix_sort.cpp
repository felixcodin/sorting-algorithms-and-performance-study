#include "../include/sorting/radix_sort.hpp"

template <typename T>
void countSort(std::vector<T> &arr, T exp)
{
    size_t n = arr.size();
    std::vector<T> output(n);
    std::vector<T> count(10, 0);

    int i = 0;
    for (i = 0; i < n; i++)
    {
        count[(arr[i]/exp) % 10] += 1;
    }

    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i]/exp) % 10] - 1] = arr[i];
        count[(arr[i]/exp) % 10] -= 1;
    }

    arr = output;
}

template <typename T>
void radixSort(std::vector<T> &arr)
{
    int n = arr.size();
    int max = 0;

    auto it = std::max_element(arr.begin(), arr.end());
    if (it != arr.end())
    {
        max = *it;
    }
    else
    {
        return ;
    }

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countSort(arr, exp);
    }
}

template void radixSort<int>(std::vector<int> &);