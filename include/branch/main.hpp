#ifndef BRANCH_MAIN_HPP
#define BRANCH_MAIN_HPP

#include <windows.h>

class Flags;

extern CRITICAL_SECTION critical_section;

extern int branch_main(const Flags& flags);

#endif // BRANCH_MAIN_HPP
