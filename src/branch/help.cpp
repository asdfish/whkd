#include <branch/help.hpp>

bool branch_help_predicate(const Flags& flags) {
  return flags['h'].set;
}
int branch_help_routine(const Flags& flags) {
  flags.print_documentation(2);
  return 0;
}
