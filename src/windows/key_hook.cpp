#include <windows/key_hook.hpp>

#include <iostream>

static std::vector<DWORD> key_presses;

std::function<bool(std::vector<DWORD>&)> KeyHook::user_callback = [] (std::vector<DWORD>&) { return false; };

KeyHook::KeyHook(const std::function<bool(std::vector<DWORD>&)>&& i_user_callback) {
  user_callback = i_user_callback;

  handle = SetWindowsHookEx(WH_KEYBOARD_LL, callback, nullptr, 0);
}
KeyHook::~KeyHook(void) {
  if(handle)
    UnhookWindowsHookEx(handle);
}
bool KeyHook::ok(void) const {
  return handle;
}

LRESULT KeyHook::callback(int code, WPARAM w_param, LPARAM l_param) {
  if(code < 0)
    return CallNextHookEx(nullptr, code, w_param, l_param);

  bool eat_key = false;

  if(code == HC_ACTION) {
    switch(w_param) {
      case WM_KEYDOWN:
      case WM_SYSKEYDOWN:
        KBDLLHOOKSTRUCT* event = (KBDLLHOOKSTRUCT*) l_param;
        key_presses.push_back(event->vkCode);

        eat_key = user_callback(key_presses);
        break;
    }
  }

  return eat_key ? 1 : CallNextHookEx(nullptr, code, w_param, l_param);
}
