#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>
#include <vector>
#include <utility>

template <typename Func, typename Arg>
double measureTime(Func func, Arg &&arg);

#endif