#include <branch/main.hpp>
#include <cli/flags.hpp>

GuardedContainer<std::vector<DWORD>> keys = GuardedContainer<std::vector<DWORD>>();

static LRESULT key_event_hook_callback(int code, LPARAM l_param, WPARAM w_param) {
}

int branch_main(const Flags&) {
  return 0;
}
