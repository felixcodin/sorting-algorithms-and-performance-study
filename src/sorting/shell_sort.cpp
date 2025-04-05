#include "../include/sorting/shell_sort.hpp"

template <typename T>
void shellSort(std::vector<T> &arr)
{
    int n = arr.size();

    std::vector<int> gap = {n / 2}; 

    while (gap.back() / 2 >= 1)
    {
        gap.push_back(gap.back() / 2);
    }

    for (int i = 0; i < gap.size(); i++)
    {
        for (int j = gap[i]; j < n; j++)
        {
            int k = j;
            T key = arr[j];
            while (k >= gap[i] && arr[k - gap[i]] >= key)
            {
                arr[k] = arr[k - gap[i]];
                k -= gap[i];
            }
            arr[k] = key;
        }
    }
}

template void shellSort<int>(std::vector<int> &);