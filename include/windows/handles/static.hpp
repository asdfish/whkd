#ifndef HANDLES_STATIC_HPP
#define HANDLES_STATIC_HPP

#include <functional>
#include <optional>

#include <windows/error.hpp>

#include <windows.h>
#include <winuser.h>

using enum_windows_function_t = std::function<BOOL(WNDENUMPROC, LPARAM)>;

static std::optional<std::vector<HWND>> get_handles_base(enum_windows_function_t callback, std::size_t handles_length);
static std::optional<std::size_t> get_handles_length_base(enum_windows_function_t callback);
static enum_windows_function_t get_enum_desktop_windows_functor(HDESK desktop);

static std::optional<std::vector<HWND>> get_handles_base(enum_windows_function_t callback, std::size_t handles_length) {
  std::vector<HWND> handles;
  handles.reserve(handles_length);

  if(callback([](HWND handle, LPARAM user_data) {
    if(!user_data)
      return FALSE;

    std::vector<HWND>* handles = (std::vector<HWND>*) user_data;
    if(handles->size() >= handles->capacity())
      return FALSE;
    handles->push_back(handle);

    return TRUE;
  }, (LPARAM) &handles) == 0) {
    print_last_error();
    return std::nullopt;
  }

  return handles;
}
static std::optional<std::size_t> get_handles_length_base(enum_windows_function_t callback) {
  std::size_t output = 0;

  if(callback([] (HWND, LPARAM user_data) {
    if(!user_data)
      return FALSE;

    std::size_t* length = (std::size_t*) user_data;
    (*length) ++;

    return TRUE;
  }, (LPARAM) &output) == 0) {
    print_last_error();
    return std::nullopt;
  }

  return output;
}
static enum_windows_function_t get_enum_desktop_windows_functor(HDESK desktop) {
  using namespace std::placeholders;
  return std::bind(EnumDesktopWindows, desktop, _1, _2);
}

#endif // HANDLES_STATIC_HPP
