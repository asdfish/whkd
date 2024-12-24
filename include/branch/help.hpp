#include <branch/base.hpp>

extern bool branch_help_predicate(const Flags& flags);
extern int branch_help_routine(const Flags& flags);

constexpr BranchBase get_branch_help(void) {
  return BranchBase(
    branch_help_predicate,
    branch_help_routine
  );
}
