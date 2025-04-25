#include "../include/utils/timer.hpp"
#include <functional>

template <typename Func, typename Arg>
double measureTime(Func func, Arg &&arg)
{
    auto start = std::chrono::high_resolution_clock::now();

    func(std::forward<Arg>(arg));

    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    return duration.count() / 1000.0;
}

template double measureTime<std::function<void(std::vector<int>&)>, std::reference_wrapper<std::vector<int>>>(std::function<void(std::vector<int>&)>, std::reference_wrapper<std::vector<int>>&&);