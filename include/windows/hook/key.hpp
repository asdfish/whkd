#ifndef HOOK_KEY_HPP
#define HOOK_KEY_HPP

#include <windows/hook/base.hpp>
#include <windows/threads/guarded_container.hpp>

extern GuardedContainer<std::vector<DWORD>> keys;

extern Hook get_hook_key(void);

#endif // HOOK_KEY_HPP
