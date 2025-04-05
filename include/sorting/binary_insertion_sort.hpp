#ifndef BINARY_INSERTION_SORT_HPP
#define BINARY_INSERTION_SORT_HPP

#include <vector>
using namespace std;

template <typename T>
int binarySearch(const vector<T> &arr, int left, int right, T key);

template <typename T>
void binaryInsertionSort(vector<T> &arr);

#endif