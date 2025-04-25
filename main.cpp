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
    int sizeOfGroupOne = n;
    int sizeOfGroupTwoAndThree = n*10*10;

    vector<int> originalVectorGroupOne = generateRandomVector<int>(sizeOfGroupOne, minElement, maxElement);
    vector<int> originalVectorGroupTwoAndThree = generateRandomVector<int>(sizeOfGroupTwoAndThree, minElement, maxElement);
    
    cout << "*********Group 1********" << endl;
    
    vector<pair<string, function<void(vector<int>&)>>> algorithmsGroupOne = {
        {"Selection Sort", selectionSort<int>},
        {"Insertion Sort", insertionSort<int>},
        {"BinaryInsertion Sort", binaryInsertionSort<int>},
        {"Bubble Sort", bubbleSort<int>},
        {"Shaker Sort", shakerSort<int>},
        {"Shell Sort", shellSort<int>}
    };

    cout << "*********Group 2*********" << endl;
    vector<pair<string, function<void(vector<int>&)>>> algorithmsGroupTwo = {
        {"Heap Sort", heapSort<int>},
        {"Merge Sort", mergeSort<int>},
        {"Natural Merge Sort", naturalMergeSort<int>},
        {"Quick Sort", quickSort<int>},
        {"std::sort", stdSort<int>}
    };

    vector<pair<string, function<void(vector<int>&)>>> algorithmsGroupThree = {
        {"Radix Sort", radixSort<int>},
        {"Counting Sort", countingSort<int>}
    };

    testSortingAlgorithms(algorithmsGroupOne, originalVectorGroupOne);
    testSortingAlgorithms(algorithmsGroupTwo, originalVectorGroupTwoAndThree);
    testSortingAlgorithms(algorithmsGroupThree, originalVectorGroupTwoAndThree);

    return 0;
}