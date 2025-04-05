#ifndef DATA_GENERATOR_HPP
#define DATA_GENERATOR_HPP

#include <vector>
#include <random>

template <typename T>
std::vector<T> generateRandomVector(int size, int min = 0, int max = 1000);

#endif