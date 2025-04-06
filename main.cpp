#include <iostream>
#include <vector>
#include <algorithm>

#include "../include/utils/timer.hpp"
#include "../include/utils/data_generator.hpp"
#include "../include/sorting/selection_sort.hpp"
#include "../include/sorting/insertion_sort.hpp"
#include "../include/sorting/binary_insertion_sort.hpp"
#include "../include/sorting/bubble_sort.hpp"
#include "../include/sorting/shaker_sort.hpp"
#include "../include/sorting/shell_sort.hpp"
#include "../include/sorting/heap_sort.hpp"
#include "../include/sorting/merge_sort.hpp"
#include "../include/sorting/natural_merge_sort.hpp"
#include "../include/sorting/quick_sort.hpp"
#include "../include/sorting/std_sort.hpp"
#include "../include/sorting/radix_sort.hpp"
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
    vector<int> arr5 = arr1;
    vector<int> arr6 = arr1;
    vector<int> arr7 = arr1;
    vector<int> arr8 = arr1;
    vector<int> arr9 = arr1;
    vector<int> arr10 = arr1;
    vector<int> arr11 = arr1;
    vector<int> arr12 = arr1;

    cout  << "******Group 1 ******" <<endl;
    double measureSelectionSort = measureTime(selectionSort<int>, ref(arr1));
    cout << "Selection Sort: " << measureSelectionSort << " ms" << endl;

    double measureInsertionSort = measureTime(insertionSort<int>,  ref(arr2));
    cout << "Insertion Sort: " << measureInsertionSort << " ms" << endl;

    double measureBinaryInsertionSort = measureTime(binaryInsertionSort<int>, ref(arr3));
    cout << "Binary Insertion Sort: " << measureBinaryInsertionSort << " ms" << endl;

    double measureBubbleSort = measureTime(bubbleSort<int>, ref(arr4));
    cout << "Bubble Sort: " << measureBubbleSort << " ms" << endl;

    double measureShakerSort = measureTime(shakerSort<int>, ref(arr5));
    cout << "Shaker Sort: " << measureShakerSort << " ms" << endl;

    double measureShellSort = measureTime(shellSort<int>, ref(arr6));
    cout << "Shell Sort: " << measureShellSort << " ms" << endl;

    cout << "******Group 2******" <<  endl;
    double measureHeapSort = measureTime(heapSort<int>, ref(arr7));
    cout << "Heap Sort: " << measureHeapSort << " ms" << endl;

    double measureMergeSort = measureTime(mergeSort<int>, ref(arr8));
    cout << "Merge Sort: " << measureMergeSort << " ms" << endl;

    double measureNaturalMergeSort = measureTime(naturalMergeSort<int>, ref(arr9));
    cout << "Natural Merge Sort: " << measureNaturalMergeSort << " ms" << endl;

    double measureQuickSort = measureTime(quickSort<int>, ref(arr10));
    cout << "Quick Sort: " << measureQuickSort << " ms" << endl;

    double measureSTDSort = measureTime(stdSort<int>, ref(arr11));
    cout << "std Sort: " << measureSTDSort << " ms" << endl;

    double measureRadixSort = measureTime(radixSort<int>, ref(arr12));
    cout << "Radix Sort: " << measureRadixSort << " ms" << endl;

    return 0;
}