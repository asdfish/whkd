#include <windows/key_translation.hpp>

std::optional<DWORD> key_to_ascii(const KBDLLHOOKSTRUCT& key) {
  BYTE keyboard_state[256];
  if(GetKeyboardState(keyboard_state) != TRUE)
    return std::nullopt;

  DWORD ascii_key = 0;
  if(ToAscii(key.vkCode, key.scanCode, keyboard_state, (LPWORD) &ascii_key, 0) != 1)
    return std::nullopt;

  return ascii_key;
}
