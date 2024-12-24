#include <branch/main.hpp>
#include <cli/flags.hpp>

CRITICAL_SECTION critical_section;
GuardedContainer<std::vector<DWORD>> keys(&critical_section);

static LRESULT key_event_hook_callback(int code, LPARAM l_param, WPARAM w_param) {
}

int branch_main(const Flags&) {
  InitializeCriticalSection(&critical_section);

  DeleteCriticalSection(&critical_section);
  return 0;
}
