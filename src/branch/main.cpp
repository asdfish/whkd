#include <branch/main.hpp>
#include <cli/flags.hpp>
#include <windows/hook/key.hpp>

#include <cstdlib>

int branch_main(const Flags&) {
  SetConsoleCtrlHandler([] (DWORD signal_type) -> BOOL {
    std::exit(signal_type);
    return FALSE;
  }, TRUE);

  try {
    Hook hook_key = get_hook_key();

    MSG message;
    while(!GetMessage(&message, nullptr, 0, 0)) {
      TranslateMessage(&message);
      DispatchMessage(&message);
    }
  } catch(...) {
    exit(-1);
  }

  return 0;
}
