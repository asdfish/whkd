#ifndef HOOK_HPP
#define HOOK_HPP

#include <windows.h>

class Hook {
  HHOOK id = nullptr;

public:
  Hook(int type, LRESULT (*i_hook) (int code, WPARAM w_param, LPARAM l_param));
  ~Hook(void);
};

#endif // HOOK_HPP
