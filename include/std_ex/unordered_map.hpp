#ifndef UNORDERED_MAP_HPP
#define UNORDERED_MAP_HPP

#include <unordered_map>

class Flag;

template <typename KEY, typename VALUE>
bool unordered_map_contains(const std::unordered_map<KEY, VALUE>& hash_map, const KEY& key);

extern template bool unordered_map_contains(const std::unordered_map<char, Flag>& hash_map, const char& key);

#endif // UNORDERED_MAP_HPP
