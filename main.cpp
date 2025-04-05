#include <iostream>
#include <vector>

#include "../include/sorting/selection_sort.hpp"
#include "../include/utils/timer.hpp"
#include "../include/utils/data_generator.hpp"
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
    vector<int> arr = generateRandomVector<int>(50, 1, 100);
    cout << "Original array: ";
    printArr(arr);

    double measureSelectionSort = measureTime(selectionSort<int>, ref(arr));
    cout << "Selection Sort: " << measureSelectionSort << " ms" << endl;

    selectionSort(arr);
    cout << "Sorted array: ";
    printArr(arr);

    return 0;
}