#ifndef HOOK_HPP
#define HOOK_HPP

#include <windows.h>

class Hook {
  LRESULT (*callback) (int code, WPARAM w_param, LPARAM l_param) = nullptr;
  HHOOK id = nullptr;

public:
  Hook(int type, LRESULT (*i_hook) (int code, WPARAM w_param, LPARAM l_param));
  ~Hook(void);
};

#endif // HOOK_HPP
