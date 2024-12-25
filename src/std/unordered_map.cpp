#include <cli/flag.hpp>
#include <std/unordered_map.hpp>

#include <stdexcept>

template <typename KEY, typename VALUE>
bool unordered_map_contains(const std::unordered_map<KEY, VALUE>& hash_map, const KEY& key) {
  try {
    hash_map.at(key);
    return true;
  } catch (const std::out_of_range&) {
    return false;
  }
}

template bool unordered_map_contains(const std::unordered_map<char, Flag>& hash_map, const char& key);
