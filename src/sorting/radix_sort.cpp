#include "../include/sorting/radix_sort.hpp"

template <typename T>
void countSort(std::vector<T> &arr, T exp)
{
    size_t n = arr.size();
    std::vector<T> output(n);
    std::vector<int> count(10, 0);

    for (size_t i = 0; i < n; i++)
    {
        count[(arr[i]/exp) % 10] += 1;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int pos = count[(arr[i] / exp) % 10] - 1;
        output[pos] = arr[i];
        count[(arr[i] / exp) % 10] -= 1;
    }

    arr = output;
}

template <typename T>
void radixSort(std::vector<T> &arr)
{
    int n = arr.size();
    if (n == 0)
    {
        return ;
    }

    auto it = std::max_element(arr.begin(), arr.end());
    T max = (it != arr.end()) ? *it : 0;
    if (it != arr.end())
    {
        max = *it;
    }
    else
    {
        return ;
    }

    for (T exp = 1; max / exp > 0; exp *= 10)
    {
        countSort(arr, exp);
    }
}

template void radixSort<int>(std::vector<int> &);