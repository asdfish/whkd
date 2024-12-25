#include <windows/key_hook.hpp>

#include <iostream>

static std::vector<DWORD> key_presses;

KeyHook::KeyHook(void) {
  handle = SetWindowsHookEx(WH_KEYBOARD_LL, callback, nullptr, 0);
}
KeyHook::~KeyHook(void) {
  if(handle)
    UnhookWindowsHookEx(handle);
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
        break;
    }
  }

  return eat_key ? 1 : CallNextHookEx(nullptr, code, w_param, l_param);
}

const std::vector<DWORD>& KeyHook::get_keys_presses(void) {
  return key_presses;
}
