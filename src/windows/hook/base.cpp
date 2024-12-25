#include <windows/hook/base.hpp>

Hook::Hook(int type, LRESULT (*callback) (int code, WPARAM w_param, LPARAM l_param)) {
  id = SetWindowsHookEx(type, callback, nullptr, 0);
}
Hook::~Hook(void) {
  if(id)
    UnhookWindowsHookEx(id);
}
