#ifndef UNORDERED_MAP_HPP
#define UNORDERED_MAP_HPP

#include <stdexcept>
#include <unordered_map>

template <typename KEY, typename VALUE>
inline bool unordered_map_contains(const std::unordered_map<KEY, VALUE>& hash_map, const KEY& key) {
  try {
    hash_map.at(key);
    return true;
  } catch (const std::out_of_range&) {
    return false;
  }
}

#endif // UNORDERED_MAP_HPP
