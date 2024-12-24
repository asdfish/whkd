#include <windows/handles/filters.hpp>

std::function<bool (HWND)> handle_filter_winapi(BOOL (*predicate) (HWND)) {
  return [&predicate] (HWND handle) {
    return predicate(handle);
  };
}
