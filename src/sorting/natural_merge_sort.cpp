#include "../include/sorting/natural_merge_sort.hpp"
#include <algorithm>
#include <utility>

static int nextGap(int gap)
{
    if (gap <= 1)
    {
        return 0;
    }
    return (gap/2) + (gap%2);
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
void naturalMergeSort(std::vector<T> &arr)
{
    int n = arr.size();

    if (n <= 1)
        return;

    std::vector<std::pair<int, int>> runs;

    int start = 0;
    while (start < n)
    {
        int end = start;
        while (end + 1 < n && arr[end] <= arr[end + 1])
        {
            end++;
        }
        runs.push_back({start, end});
        start = end + 1;
    }

    while (runs.size() > 1)
    {
        std::vector<std::pair<int, int>> newRuns;

        for (size_t i = 0; i + 1 < runs.size(); i += 2)
        {
            int left = runs[i].first;
            int right = runs[i + 1].second;

            merge(arr, left, right);
            newRuns.push_back({left, right});
        }

        if (runs.size() % 2 == 1)
        {
            newRuns.push_back(runs.back());
        }

        runs = std::move(newRuns);
    }
}

template void naturalMergeSort<int>(std::vector<int> &);