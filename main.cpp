#include <iostream>
#include <vector>
#include <algorithm>

#include "../include/utils/timer.hpp"
#include "../include/utils/data_generator.hpp"
#include "../include/sorting/selection_sort.hpp"
#include "../include/sorting/insertion_sort.hpp"
#include "../include/sorting/binary_insertion_sort.hpp"
#include "../include/sorting/bubble_sort.hpp"
using namespace std;

template <typename T>
void printArr(vector<T> arr)
{
    for (T a : arr)
    {
        cout << a << " ";
    }
    cout << endl;
}

int main()
{
    int n, k;
    cout << "Enter the size of array: ";
    cin >> n;
    cout << "Enter [0, k] (k > 10^9): k = ";
    cin >> k;

    vector<int> arr1 = generateRandomVector<int>(n, 0, k);
    vector<int> arr2 = arr1;
    vector<int> arr3 = arr1;
    vector<int> arr4 = arr1;

    double measureSelectionSort = measureTime(selectionSort<int>, ref(arr1));
    cout << "Selection Sort: " << measureSelectionSort << " ms" << endl;

    double measureInsertionSort = measureTime(insertionSort<int>,  ref(arr2));
    cout << "Insertion Sort: " << measureInsertionSort << " ms" << endl;

    double measureBinaryInsertionSort = measureTime(binaryInsertionSort<int>, ref(arr3));
    cout << "Binary Insertion Sort: " << measureBinaryInsertionSort << " ms" << endl;

    double measureBubbleSort = measureTime(bubbleSort<int>, ref(arr4));
    cout << "Bubble Sort: " << measureBubbleSort << " ms" << endl;

    return 0;
}