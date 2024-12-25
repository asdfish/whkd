#ifndef CRITICAL_SECTION_GUARD_HPP
#define CRITICAL_SECTION_GUARD_HPP

#include <windows.h>

class CriticalSectionGuard {
  CRITICAL_SECTION* critical_section = nullptr;

public:
  CriticalSectionGuard(CRITICAL_SECTION* i_critical_section);
  ~CriticalSectionGuard(void);
};

#endif // CRITICAL_SECTION_GUARD_HPP
