#include <functional.hpp>
#include <windows/error.hpp>
#include <windows/handles/public.hpp>
#include <windows/handles/static.hpp>

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
  using input_t = HWND;
  using output_t = std::optional<std::string>;

  std::vector<output_t> output = map<input_t, output_t>(handles, [](const input_t& handle) -> output_t {
    int length = GetWindowTextLengthA(handle) + 1;
    if(length <= 0) {
      print_last_error();
      return std::nullopt;
    }

    std::vector<char> text_raw;
    text_raw.reserve(length);

    if(GetWindowTextA(handle, text_raw.data(), length) <= 0) {
      print_last_error();
      return std::nullopt;
    }

    std::string text = std::string(text_raw.data());
    return text;
  });

  return output;
}
