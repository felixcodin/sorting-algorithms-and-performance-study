#include <iostream>

#include "../include/utils/checker.hpp"
#include "../include/utils/data_generator.hpp"
#include "../include/utils/timer.hpp"

template <typename T>
void testSortingAlgorithm(const std::string &name, std::function<void(std::vector<T>&)> sortFunc, const std::vector<T> &originalVector)
{
    std::vector<T> vec = originalVector;
    double timeTaken = measureTime(sortFunc, ref(vec));
    std::cout << name << ": " << timeTaken << " ms" << std::endl;
}

template <typename T>
void testSortingAlgorithms(const std::vector<std::pair<std::string, std::function<void(std::vector<T>&)>>> &algorithms, const std::vector<T> &originalVector)
{
    for (const auto &algorithm : algorithms)
    {
        const std::string &name = algorithm.first;
        const auto &sortFunc = algorithm.second;

        testSortingAlgorithm(name, sortFunc, originalVector);
    }
}

template void testSortingAlgorithm<int>(
    const std::string &,
    std::function<void(std::vector<int> &)>,
    const std::vector<int> &
);

template void testSortingAlgorithms<int>(
    const std::vector<std::pair<
        std::string,
        std::function<void(std::vector<int> &)>
    >> &, 
    const std::vector<int> &
);

