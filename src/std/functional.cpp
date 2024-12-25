#include <std/functional.hpp>

template <typename T>
void filter(std::vector<T>& subject, bool (*predicate) (const T&)) {
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
void filter(std::vector<T>& subject, const std::function<bool(const T&)>& predicate) {
  std::size_t i = 0;
  while(i < subject.size()) {
    if(predicate(subject[i])) {
      subject.erase(subject.begin() + i);
      continue;
    }

    i ++;
  }
}

template <typename IN_ITERATOR, typename IN, typename OUT>
void map(IN_ITERATOR begin, IN_ITERATOR end, std::vector<OUT>& output, OUT (*converter) (const IN&)) {
  for(IN_ITERATOR i = begin; i != end; i ++)
    output.push_back(converter(*i));
}
template <typename IN_ITERATOR, typename IN, typename OUT>
std::vector<OUT> map(IN_ITERATOR begin, IN_ITERATOR end, OUT (*converter) (const IN&)) {
  std::vector<OUT> output;
  output.reserve(std::distance(begin, end));

  map(begin, end, output, converter);
  return output;
}
