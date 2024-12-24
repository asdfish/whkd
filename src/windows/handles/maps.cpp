#include <windows/handles/maps.hpp>
#include <windows/error.hpp>

#include <iostream>
#include <vector>

std::optional<std::string> handle_map_to_string(const HWND& handle) {
  int length = GetWindowTextLengthA(handle);
  if(length <= 0)
    return std::nullopt;

  length ++;

  std::vector<char> buffer;
  buffer.reserve(length);

  std::cout << buffer.data() << '\n';

  if(GetWindowTextA(handle, (LPSTR) buffer.data(), length) > 0)
    return std::string(buffer.data());

  return std::nullopt;
}
std::optional<RECT> handle_map_to_rect(const HWND& handle) {
  RECT rect;
  if(!GetWindowRect(handle, &rect)) {
    print_last_error();
    return std::nullopt;
  }

  return rect;
}
