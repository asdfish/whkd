#ifndef FUNCTIONAL_HPP
#define FUNCTIONAL_HPP

#include <cstdlib>
#include <iterator>
#include <functional>
#include <vector>

template <typename T>
inline void filter(std::vector<T>& subject, bool (*predicate) (const T&)) {
  std::size_t i = 0;
  while(i < subject.size()) {
    if(predicate(subject[i])) {
      subject.erase(subject.begin() + i);
      continue;
    }

    i ++;
  }
}
template <typename T>
inline std::vector<T> filter_copy(const std::vector<T>& original, bool(*predicate)(const T&)) {
  std::vector<T> output;
  output.reserve(original.size());

  for(const T& i : original)
    if(predicate(i))
      output.push_back(i);

  return output;
}

template <typename IN_ITERATOR, typename IN, typename OUT>
inline void map(IN_ITERATOR begin, IN_ITERATOR end, std::vector<OUT>& output, OUT (*converter) (const IN&)) {
  for(IN_ITERATOR i = begin; i != end; i ++)
    output.push_back(converter(*i));
}
template <typename IN_ITERATOR, typename IN, typename OUT>
inline std::vector<OUT> map(IN_ITERATOR begin, IN_ITERATOR end, OUT (*converter) (const IN&)) {
  std::vector<OUT> output;
  output.reserve(std::distance(begin, end));

  map(begin, end, output, converter);
  return output;
}

#endif // FUNCTIONAL_HPP
