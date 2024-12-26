#include <branch/main.hpp>
#include <cli/flag.hpp>
#include <cli/flags.hpp>
#include <macros.hpp>
#include <windows/key_hook.hpp>
#include <windows/error.hpp>
#include <main.hpp>

#include <cstdlib>

int branch_main(void) {
  if(flags['l'].set)
    std::atexit([] {
      std::cerr << "Exiting\n";
    });

  SetConsoleCtrlHandler([] (DWORD signal_type) -> BOOL {
    std::exit(signal_type);
    return FALSE;
  }, TRUE);

  try {
    LOG(flags, "Installing key hooks");
    KeyHook key_hook = KeyHook([](std::vector<DWORD>& keys) -> bool {
      return false;
    });
    if(!key_hook.ok()) {
      print_last_error();
      return -1;
    }

    LOG(flags, "Waiting for messages");
    MSG message;
    while(!GetMessage(&message, nullptr, 0, 0)) {
      TranslateMessage(&message);
      DispatchMessage(&message);
    }
  } catch(...) {
    std::exit(-1);
  }

  return 0;
}
