#include <std/functional.hpp>
#include <windows/error.hpp>
#include <windows/handles/main.hpp>
#include "static.hpp"

#include <winuser.h>

std::optional<std::vector<HWND>> get_handles(void) {
  std::optional<std::size_t> handles_length = get_handles_length();

  if(!handles_length.has_value())
    return std::nullopt;

  return get_handles_base(EnumWindows, handles_length.value());
}
std::optional<std::vector<HWND>> get_handles(HDESK desktop) {
  std::optional<std::size_t> handles_length = get_handles_length(desktop);

  if(!handles_length.has_value())
    return std::nullopt;

  return get_handles_base(get_enum_desktop_windows_functor(desktop), handles_length.value());
}

std::optional<std::size_t> get_handles_length(void) {
  return get_handles_length_base(EnumWindows);
}
std::optional<std::size_t> get_handles_length(HDESK desktop) {
  return get_handles_length_base(get_enum_desktop_windows_functor(desktop));
}
