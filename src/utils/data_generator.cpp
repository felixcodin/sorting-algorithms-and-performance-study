#include "../include/utils/data_generator.hpp"
#include <algorithm>
#include <numeric>

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

template <typename T>
std::vector<T> generateAlreadySortedVector(int size, int mn, int mx)
{
    std::vector<T> vec(size);
    std::uniform_int_distribution<> distribution(mn, mx);

    for (int i = 0; i < size; i++)
    {
        vec[i] = distribution(gen);
    }

    std::vector<T> S(size);
    std::partial_sum(vec.begin(), vec.end(), S.begin());
    T prefixSum = S[size - 1];

    std::vector<T> res(size);
    T range = mx - mn;
    for (int i = 0; i < size; i++)
    {
        double u = static_cast<double>(S[i] / static_cast<double>(prefixSum));
        res[i] = mn + static_cast<T>(u * range);
    }
    
    return res;
}

template <typename T>
std::vector<T> generateReverseSortedVector(int size, int mn, int mx)
{
    std::vector<T> resTemp = generateAlreadySortedVector<T>(size, mn, mx);
    std::vector<T> res(size);
    for(int i = 0; i < size; i++)
    {
        res[i] = resTemp[size - i - 1];
    }

    return res;
}

template <typename T>
std::vector<T> generateNearlySortedVector(int size, int mn, int mx)
{
    std::vector<T> res = generateAlreadySortedVector<T>(size, mn, mx);

    std::uniform_int_distribution<> dis(0, size - 2);
    
    int swaps = size/5;

    for (int i = 0; i < swaps; i++)
    {
        int index = dis(gen);
        std::swap(res[index], res[index + 1]);
    }

    return res;
}

template std::vector<int> generateRandomVector<int>(int, int, int);
template std::vector<int> generateAlreadySortedVector<int>(int, int, int);
template std::vector<int> generateReverseSortedVector<int>(int, int, int);
template std::vector<int> generateNearlySortedVector<int>(int, int, int);