#include <windows/error.hpp>
#include <windows/handles/getters.hpp>

#include <winuser.h>

std::optional<std::vector<HWND>> get_handles(void) {
  std::optional<std::size_t> handles_length = get_handles_length();
  if(!handles_length || !*handles_length)
    return std::nullopt;

  std::vector<HWND> handles;
  handles.reserve(*handles_length);

  if(
    !EnumWindows([](HWND handle, LPARAM handles_ptr) -> BOOL {
      if(!handles_ptr)
        return FALSE;

      std::vector<HWND>* handles = (std::vector<HWND>*) handles_ptr;
      handles->push_back(handle);

      return TRUE;
    }, (LPARAM) &handles)
  ) {
    print_last_error();
    return std::nullopt;
  }

  return handles;
}
std::optional<std::size_t> get_handles_length(void) {
  std::size_t length = 0;

  if(
    !EnumWindows([](HWND, LPARAM length_ptr) -> BOOL {
      if(!length_ptr)
        return FALSE;

      std::size_t* length = (std::size_t*) length_ptr;
      *length = *length + 1;

      return TRUE;
    }, (LPARAM) &length)
  ) {
    print_last_error();
    return std::nullopt;
  }

  return length;
}
