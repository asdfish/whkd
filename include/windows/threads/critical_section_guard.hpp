#ifndef CRITICAL_SECTION_GUARD_HPP
#define CRITICAL_SECTION_GUARD_HPP

#include <windows.h>

class CriticalSectionGuard {
public:
  CriticalSectionGuard(CRITICAL_SECTION* critical_section);
  ~CriticalSectionGuard(void);

private:
  CRITICAL_SECTION* critical_section = nullptr;
};

#endif // CRITICAL_SECTION_GUARD_HPP
