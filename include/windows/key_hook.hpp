#ifndef KEY_HOOK_HPP
#define KEY_HOOK_HPP

#include <windows.h>

#include <optional>
#include <vector>

class KeyHook {
  HHOOK handle = nullptr;

  static LRESULT callback(int code, WPARAM w_param, LPARAM l_param);

public:
  KeyHook(void);
  ~KeyHook(void);

  static const std::vector<DWORD>& get_keys_presses(void);
};

#endif // KEY_HOOK_HPP
