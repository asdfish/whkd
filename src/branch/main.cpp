#include <branch/main.hpp>
#include <cli/flag.hpp>
#include <cli/flags.hpp>
#include <config.hpp>
#include <hotkey.hpp>
#include <macros.hpp>
#include <windows/key_hook.hpp>
#include <windows/error.hpp>

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
    LOG(flags, "Installing key hooks");
    KeyHook key_hook = KeyHook([&flags](std::vector<DWORD>& keys) -> bool {
      bool contains = false;
      std::optional<size_t> match = std::nullopt;
      for(size_t i = 0; i < hotkeys.size() && !match.has_value(); i ++)
        switch(hotkeys[i].get_inputs_status(keys)) {
          case INPUTS_CONTAIN:
            contains = true;
            continue;
          case INPUTS_MATCH:
            match = i;
            continue;
        }

      if(!contains && !match) {
        LOG(flags, "Clearing");
        return false;
      }

      return true;
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
