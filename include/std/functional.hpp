#ifndef FUNCTIONAL_HPP
#define FUNCTIONAL_HPP

#include <cstdlib>
#include <iterator>
#include <functional>
#include <vector>

template <typename T>
void filter(std::vector<T>& subject, bool (*predicate) (const T&));
template <typename T>
void filter(std::vector<T>& subject, const std::function<bool(const T&)>& predicate);

template <typename IN_ITERATOR, typename IN, typename OUT>
void map(IN_ITERATOR begin, IN_ITERATOR end, std::vector<OUT>& output, OUT (*converter) (const IN&));
template <typename IN_ITERATOR, typename IN, typename OUT>
std::vector<OUT> map(IN_ITERATOR begin, IN_ITERATOR end, OUT (*converter) (const IN&));

#endif // FUNCTIONAL_HPP
