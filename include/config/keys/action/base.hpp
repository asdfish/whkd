#ifndef KEY_ACTION_BASE_HPP
#define KEY_ACTION_BASE_HPP

#include <windows.h>

#include <vector>

class KeyActionBase {
public:
  virtual ~KeyActionBase(void) = default;
  virtual void execute(std::vector<HWND>& handles) const;
};

#endif // KEY_ACTION_BASE_HPP
