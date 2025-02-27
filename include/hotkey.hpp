#ifndef HOTKEY_HPP
#define HOTKEY_HPP

#include <windows.h>

#include <vector>

enum InputsStatus {
  INPUTS_CONTAIN,
  INPUTS_MATCH,
  INPUTS_NO_MATCH,
};

class Hotkey {
  const char* command;
  std::vector<DWORD> keys;

public:
  Hotkey(const char* command, std::vector<DWORD>&& keys);
  void execute(void) const;
  const char* get_command(void) const;
  InputsStatus get_inputs_status(const std::vector<DWORD>& inputs) const;
};

#endif // HOTKEY_HPP
