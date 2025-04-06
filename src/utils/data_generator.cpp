#include "../include/utils/data_generator.hpp"

std::random_device rd;
std::mt19937 gen(rd());

template <typename T>
std::vector<T> generateRandomVector(int size, int min, int max) 
{
    std::vector<T> vec(size);
    std::uniform_int_distribution<> distrib(min, max);
  
    for (int i = 0; i < size; i++) 
    {
        vec[i] = distrib(gen);
    }
  
    return vec;
}

int generateRandomNumber(int min, int max)
{
    std::uniform_int_distribution<> distribution(min, max);
    return distribution(gen);
}

template std::vector<int> generateRandomVector<int>(int, int, int);