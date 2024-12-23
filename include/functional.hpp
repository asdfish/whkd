#ifndef FUNCTIONAL_HPP
#define FUNCTIONAL_HPP

#include <vector>

template <typename IN, typename OUT>
std::vector<OUT> map(const std::vector<IN>& input, OUT (*converter) (const IN&)) {
  std::vector<OUT> output;
  output.reserve(input.size());

  for(const IN& i : input)
    output.push_back(converter(i));

  return output;
}

#endif // FUNCTIONAL_HPP
