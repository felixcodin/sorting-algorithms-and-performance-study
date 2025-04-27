#include <iostream>
#include <vector>
#include <algorithm>

//#include "../include/utils/timer.hpp"
#include "../include/utils/data_generator.hpp"
#include "../include/utils/checker.hpp"
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
#include "../include/sorting/counting_sort.hpp"
using namespace std;

int main()
{
    int n, k;
    cout << "Enter the size of array: ";
    cin >> n;
    cout << "Enter [0, k] (k > 10^9): k = ";
    cin >> k;

    int maxElement = k;
    int minElement = 0;
    for (int i = 1; i <= 1; i += 2)
    {
        int sizeOfGroupOne = n*i;
        int sizeOfGroupTwoAndThree = n*i*10*10;

        vector<int> originalVectorGroupOne = generateRandomVector<int>(sizeOfGroupOne, minElement, maxElement);
        vector<int> originalVectorGroupTwoAndThree = generateRandomVector<int>(sizeOfGroupTwoAndThree, minElement, maxElement);
        vector<int> originalSortedVectorGroupOne = generateAlreadySortedVector<int>(sizeOfGroupOne, minElement, maxElement);
        vector<int> originalSortedVectorGroupTwoAndThree = generateAlreadySortedVector<int>(sizeOfGroupTwoAndThree, minElement, maxElement);
        vector<int> originalReverseSortedVectorGroupOne = generateReverseSortedVector<int>(sizeOfGroupOne, minElement, maxElement);
        vector<int> originalReverseSortedVectorGroupTwoAndThree = generateReverseSortedVector<int>(sizeOfGroupTwoAndThree, minElement, maxElement);
        vector<int> originalNearlySortedVectorGroupOne = generateNearlySortedVector<int>(sizeOfGroupOne, minElement, maxElement);
        vector<int> originalNearlySortedVectorGroupTwoAndThree = generateNearlySortedVector<int>(sizeOfGroupTwoAndThree, minElement, maxElement);

        vector<pair<string, function<void(vector<int>&)>>> algorithmsGroupOne = {
            {"Selection Sort", selectionSort<int>},
            {"Insertion Sort", insertionSort<int>},
            {"BinaryInsertion Sort", binaryInsertionSort<int>},
            {"Bubble Sort", bubbleSort<int>},
            {"Shaker Sort", shakerSort<int>},
            {"Shell Sort", shellSort<int>},
            {"Heap Sort", heapSort<int>},
            {"Merge Sort", mergeSort<int>},
            {"Natural Merge Sort", naturalMergeSort<int>},
            {"Quick Sort", quickSort<int>},
            {"std::sort", stdSort<int>},
            {"Radix Sort", radixSort<int>},
            {"Counting Sort", countingSort<int>}
        };

        vector<pair<string, function<void(vector<int>&)>>> algorithmsGroupTwo = {
            {"Heap Sort", heapSort<int>},
            {"Merge Sort", mergeSort<int>},
            {"Natural Merge Sort", naturalMergeSort<int>},
            {"Quick Sort", quickSort<int>},
            {"std::sort", stdSort<int>},
            {"Shell Sort", shellSort<int>},
            {"Radix Sort", radixSort<int>},
            {"Counting Sort", countingSort<int>}
        };

        vector<pair<string, function<void(vector<int>&)>>> algorithmsGroupOneWithAlreadySortedVector = {
            {"Selection Sort", selectionSort<int>},
            {"Insertion Sort", insertionSort<int>},
            {"Binary Insertion Sort", binaryInsertionSort<int>},
            {"Bubble Sort", bubbleSort<int>},
            {"Shaker Sort", shakerSort<int>},
            {"Shell Sort", shellSort<int>},
            {"Heap Sort", heapSort<int>},
            {"Merge Sort", mergeSort<int>},
            {"Natural Merge Sort", naturalMergeSort<int>},
            {"Quick Sort", quickSort<int>},
            {"std::sort", stdSort<int>},
            {"Radix Sort", radixSort<int>},
            {"Counting Sort", countingSort<int>}
        };

        vector<pair<string, function<void(vector<int>&)>>> algorithmsGroupTwoWithAlreadySortedVector = {
            {"Heap Sort", heapSort<int>},
            {"Merge Sort", mergeSort<int>},
            {"Natural Merge Sort", naturalMergeSort<int>},
            {"Quick Sort", quickSort<int>},
            {"std::sort", stdSort<int>},
            {"Shell Sort", shellSort<int>},
            {"Radix Sort", radixSort<int>},
            {"Counting Sort", countingSort<int>}
        };

        vector<pair<string, function<void(vector<int>&)>>> algorithmsGroupOneWithReverseSortedVector = {
            {"Selection Sort", selectionSort<int>},
            {"Insertion Sort", insertionSort<int>},
            {"Binary Insertion Sort", binaryInsertionSort<int>},
            {"Bubble Sort", bubbleSort<int>},
            {"Shaker Sort", shakerSort<int>},
            {"Shell Sort", shellSort<int>},
            {"Heap Sort", heapSort<int>},
            {"Merge Sort", mergeSort<int>},
            {"Natural Merge Sort", naturalMergeSort<int>},
            {"Quick Sort", quickSort<int>},
            {"std::sort", stdSort<int>},
            {"Radix Sort", radixSort<int>},
            {"Counting Sort", countingSort<int>}
        };

        vector<pair<string, function<void(vector<int>&)>>> algorithmsGroupTwoWithReverseSortedVector = {
            {"Heap Sort", heapSort<int>},
            {"Merge Sort", mergeSort<int>},
            {"Natural Merge Sort", naturalMergeSort<int>},
            {"Quick Sort", quickSort<int>},
            {"std::sort", stdSort<int>},
            {"Shell Sort", shellSort<int>},
            {"Radix Sort", radixSort<int>},
            {"Counting Sort", countingSort<int>}
        };

        vector<pair<string, function<void(vector<int>&)>>> algorithmsGroupOneWithNearlySortedVector = {
            {"Selection Sort", selectionSort<int>},
            {"Insertion Sort", insertionSort<int>},
            {"Binary Insertion Sort", binaryInsertionSort<int>},
            {"Bubble Sort", bubbleSort<int>},
            {"Shaker Sort", shakerSort<int>},
            {"Shell Sort", shellSort<int>},
            {"Heap Sort", heapSort<int>},
            {"Merge Sort", mergeSort<int>},
            {"Natural Merge Sort", naturalMergeSort<int>},
            {"Quick Sort", quickSort<int>},
            {"std::sort", stdSort<int>},
            {"Radix Sort", radixSort<int>},
            {"Counting Sort", countingSort<int>}
        };

        vector<pair<string, function<void(vector<int>&)>>> algorithmsGroupTwoWithNearlySortedVector = {
            {"Heap Sort", heapSort<int>},
            {"Merge Sort", mergeSort<int>},
            {"Natural Merge Sort", naturalMergeSort<int>},
            {"Quick Sort", quickSort<int>},
            {"std::sort", stdSort<int>},
            {"Shell Sort", shellSort<int>},
            {"Radix Sort", radixSort<int>},
            {"Counting Sort", countingSort<int>}
        };

        cout << endl << "RANDOM VECTOR";
        cout << endl << "\t\t Experiment 1 (n = " << sizeOfGroupOne << ", k = " << k << ")" << endl;
        testSortingAlgorithms(algorithmsGroupOne, originalVectorGroupOne);
        cout << endl << "\t\t Experiment 2 (n = " << sizeOfGroupTwoAndThree << ", k = " << k << ")" << endl;
        testSortingAlgorithms(algorithmsGroupTwo, originalVectorGroupTwoAndThree);

        cout << endl << "RANDOM ALREADY VECTOR";
        cout << endl << "\t\t Experiment 1 (n = " << sizeOfGroupOne << ", k = " << k << ")" << endl;
        testSortingAlgorithms(algorithmsGroupOneWithAlreadySortedVector, originalSortedVectorGroupOne);
        cout << endl << "\t\t Experiment 2 (n = " << sizeOfGroupTwoAndThree << ", k = " << k << ")" << endl;
        testSortingAlgorithms(algorithmsGroupTwoWithAlreadySortedVector, originalSortedVectorGroupTwoAndThree);

        cout << endl << "RANDOM REVERSE SORTED VECTOR";
        cout << endl << "\t\t Experiment 1 (n = " << sizeOfGroupOne << ", k = " << k << ")" << endl;
        testSortingAlgorithms(algorithmsGroupOneWithReverseSortedVector, originalReverseSortedVectorGroupOne);
        cout << endl << "\t\t Experiment 2 (n = " << sizeOfGroupTwoAndThree << ", k = " << k << ")" << endl;
        testSortingAlgorithms(algorithmsGroupTwoWithReverseSortedVector, originalReverseSortedVectorGroupTwoAndThree);

        cout << endl << "RANDOM NEARLY SORTED VECTOR";
        cout << endl << "\t\t Experiment 1 (n = " << sizeOfGroupOne << ", k = " << k << ")" << endl;
        testSortingAlgorithms(algorithmsGroupOneWithNearlySortedVector, originalNearlySortedVectorGroupOne);
        cout << endl << "\t\t Experiment 2 (n = " << sizeOfGroupTwoAndThree << ", k = " << k << ")" << endl;
        testSortingAlgorithms(algorithmsGroupTwoWithNearlySortedVector, originalNearlySortedVectorGroupTwoAndThree);
    }

    return 0;
}