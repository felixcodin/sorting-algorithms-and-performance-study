#ifndef DATA_GENERATOR_HPP
#define DATA_GENERATOR_HPP

#include <vector>
#include <random>

template <typename T>
std::vector<T> generateRandomVector(int size, int min = 0, int max = 1000);

int generateRandomNumber(int min, int max);

template<typename T>
std::vector<T> generateAlreadySortedVector(int size, int mn, int mx);

template<typename T>
std::vector<T> generateReverseSortedVector(int size, int mn, int mx);

template<typename T>
std::vector<T> generateNearlySortedVector(int size, int mn, int mx);

#endif