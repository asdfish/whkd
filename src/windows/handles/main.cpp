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

std::vector<std::optional<std::string>> get_handle_texts(const std::vector<HWND>& handles) {
  using iterator_t = std::vector<HWND>::const_iterator;
  using output_t = std::optional<std::string>;
  std::vector<output_t> output = map <iterator_t, output_t>
    (handles.cbegin(), handles.cend(), [](const iterator_t& handle) -> output_t {
      int text_length = GetWindowTextLengthA(*handle);
      if(text_length <= 0)
        return std::nullopt;

      text_length ++;
      std::vector<char> buffer;
      buffer.reserve(text_length);

      if(GetWindowTextA(*handle, buffer.data(), text_length) <= 0)
        return std::nullopt;

      return std::string(buffer.data());
    });

  return output;
}
