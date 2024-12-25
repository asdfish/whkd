#include <branch/main.hpp>
#include <cli/flag.hpp>
#include <cli/flags.hpp>
#include <macros.hpp>
#include <windows/hook/base.hpp>
#include <windows/hook/key.hpp>

#include <cstdlib>

int branch_main(const Flags& flags) {
  if(flags['l'].set)
    std::atexit([] {
      std::cerr << "Exiting\n";
    });

  SetConsoleCtrlHandler([] (DWORD signal_type) -> BOOL {
    std::exit(signal_type);
    return FALSE;
  }, TRUE);

  try {
    LOG(flags, "Installing key hook");
    Hook hook_key = create_hook_key();

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
