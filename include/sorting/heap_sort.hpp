#ifndef HEAP_SORT_HPP
#define HEAP_SORT_HPP

#include <vector>

template <typename T>
void heapify(std::vector<T> &arr, int n, int i);

template <typename T>
void heapSort(std::vector<T> &arr);

#endif