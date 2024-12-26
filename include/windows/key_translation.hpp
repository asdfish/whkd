#ifndef KEY_TRANSLATION_HPP
#define KEY_TRANSLATION_HPP

#include <windows.h>

#include <optional>

extern std::optional<DWORD> key_to_ascii(const KBDLLHOOKSTRUCT& keyboard_state);

#endif // KEY_TRANSLATION_HPP
