#ifndef CHECKER_HPP
#define CHECKER_HPP

#include <string>
#include <functional>

template <typename T>
void testSortingAlgorithms(const std::vector<std::pair<std::string, std::function<void(std::vector<T>&)>>> &algorithms, const std::vector<T> &originalVector);


#endif