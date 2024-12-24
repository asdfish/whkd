#include <branch/help.hpp>
#include <cli/flag.hpp>

#include <iostream>

bool branch_help_predicate(const Flags& flags) {
  return flags['h'].set;
}
int branch_help_routine(const Flags& flags) {
  std::cout << "wwm: windows window manager\n"
               "Usage: wwm [OPTIONS]...\n"
               "\n"
               "Options:\n";
  flags.print_documentation(2);
  return 0;
}
