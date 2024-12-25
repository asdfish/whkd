#ifndef BRANCH_MAIN_HPP
#define BRANCH_MAIN_HPP

#include <windows/threads/guarded_container.hpp>

#include <windows.h>

#include <vector>

class Flags;

extern CRITICAL_SECTION critical_section;
extern GuardedContainer<std::vector<DWORD>> keys;

extern int branch_main(const Flags& flags);

#endif // BRANCH_MAIN_HPP
