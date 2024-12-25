#include <windows/hook/base.hpp>

#include <iostream>
Hook::Hook(int type, LRESULT (*i_callback) (int code, WPARAM w_param, LPARAM l_param)):
  callback(i_callback) {
  id = SetWindowsHookEx(type, callback, nullptr, 0);
}
Hook::~Hook(void) {
  if(id)
    UnhookWindowsHookEx(id);
  std::cout << "hook dtor\n";
}
