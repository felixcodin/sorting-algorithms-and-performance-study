#include "../include/utils/data_generator.hpp"

template <typename T>
std::vector<T> generateRandomVector(int size, int min, int max) 
{
    std::vector<T> vec(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);
  
    for (T i = 0; i < size; i++) 
    {
        vec[i] = distrib(gen);
    }
  
    return vec;
}

template std::vector<int> generateRandomVector<int>(int, int, int);