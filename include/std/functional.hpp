#ifndef FUNCTIONAL_HPP
#define FUNCTIONAL_HPP

#include <iterator>
#include <vector>

template <typename IN_ITERATOR, typename OUT>
inline void map(IN_ITERATOR begin, IN_ITERATOR end, std::vector<OUT>& output, OUT (*converter) (const IN_ITERATOR&)) {
  for(IN_ITERATOR i = begin; i != end; i ++)
    output.push_back(converter(i));
}
template <typename IN_ITERATOR, typename OUT>
inline std::vector<OUT> map(IN_ITERATOR begin, IN_ITERATOR end, OUT (*converter) (const IN_ITERATOR&)) {
  std::vector<OUT> output;
  output.reserve(std::distance(begin, end));

  map(begin, end, output, converter);
  return output;
}

#endif // FUNCTIONAL_HPP
