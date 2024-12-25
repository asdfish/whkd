#include <windows/hook/base.hpp>
#include <windows/hook/key.hpp>

GuardedContainer<std::vector<DWORD>> keys = GuardedContainer<std::vector<DWORD>>();

static LRESULT hook_key_callback(int code, WPARAM w_param, LPARAM l_param) {
  if(code < 0)
    return CallNextHookEx(nullptr, code, w_param, l_param);

  bool eat_key = false;

  if(code == HC_ACTION) {
    switch(w_param) {
      case WM_KEYDOWN:
      case WM_SYSKEYDOWN:
        KBDLLHOOKSTRUCT* event = (KBDLLHOOKSTRUCT*) l_param;
        keys.write<KBDLLHOOKSTRUCT*>([](std::vector<DWORD>& keys, KBDLLHOOKSTRUCT*& event) {
          keys.push_back(event->vkCode);
        }, event);
        break;
    }
  }

  return eat_key ? 1 : CallNextHookEx(nullptr, code, w_param, l_param);
}

Hook create_hook_key(void) {
  return Hook(WH_KEYBOARD_LL, hook_key_callback);
}
