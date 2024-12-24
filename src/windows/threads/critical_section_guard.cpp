#include <windows/threads/critical_section_guard.hpp>

CriticalSectionGuard::CriticalSectionGuard(CRITICAL_SECTION* critical_section) {
  EnterCriticalSection(critical_section);
  this->critical_section = critical_section;
}
CriticalSectionGuard::~CriticalSectionGuard(void) {
  if(critical_section)
    LeaveCriticalSection(critical_section);
}
