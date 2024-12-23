#include <windows/error.hpp>

#include <windows.h>
#include <winbase.h>

#include <iostream>

void print_last_error(void) {
  DWORD last_error = GetLastError();

  LPSTR error_message = nullptr;
  if(
    FormatMessage(
      FORMAT_MESSAGE_ALLOCATE_BUFFER |
      FORMAT_MESSAGE_FROM_SYSTEM |
      FORMAT_MESSAGE_IGNORE_INSERTS,
      nullptr,
      last_error,
      0,
      (LPTSTR) &error_message,
      0,
      nullptr
    ) == 0
  )
    return;

  if(error_message) {
    std::cerr << error_message;
    LocalFree(error_message);
  }
}
