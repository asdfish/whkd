#include <windows/threads/critical_section_guard.hpp>

CriticalSectionGuard::CriticalSectionGuard(CRITICAL_SECTION* i_critical_section):
  critical_section(i_critical_section) {
  if(critical_section)
    EnterCriticalSection(critical_section);
}
CriticalSectionGuard::~CriticalSectionGuard(void) {
  if(critical_section)
    LeaveCriticalSection(critical_section);
}
