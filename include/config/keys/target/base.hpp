#ifndef KEY_TARGET_HPP
#define KEY_TARGET_HPP

#include <windows.h>

#include <vector>

class KeyTargetBase {
public:
  virtual ~KeyTargetBase(void) = default;
  virtual std::vector<HWND> get(void) const = 0;
};

#endif // KEY_TARGET_HPP
