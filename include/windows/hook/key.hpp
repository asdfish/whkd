#ifndef HOOK_KEY_HPP
#define HOOK_KEY_HPP

#include <windows/threads/guarded_container.hpp>

class Hook;

extern GuardedContainer<std::vector<DWORD>> keys;

// aka keylogger
extern Hook create_hook_key(void);

#endif // HOOK_KEY_HPP
