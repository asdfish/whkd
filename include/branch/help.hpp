#include <branch/base.hpp>

constexpr BranchBase get_branch_help(void) {
  return BranchBase(
    [](const Flags& flags) -> bool {
      return flags['h'].set;
    },
    [](const Flags&) {
      return 0;
    }
  );
}
