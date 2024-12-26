#ifndef KEY_HOOK_HPP
#define KEY_HOOK_HPP

#include <windows.h>

#include <functional>
#include <vector>

class KeyHook {
  HHOOK handle = nullptr;
  static std::function<bool(std::vector<DWORD>&)> user_callback;

  static LRESULT callback(int code, WPARAM w_param, LPARAM l_param);
  static std::optional<DWORD> key_to_ascii(const KBDLLHOOKSTRUCT* key);

public:
  KeyHook(const std::function<bool(std::vector<DWORD>&)>&& i_user_callback);
  ~KeyHook(void);
  bool ok(void) const;
  static const std::vector<DWORD>& get_keys_presses(void);
};

#endif // KEY_HOOK_HPP
