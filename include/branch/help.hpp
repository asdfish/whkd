#ifndef BRANCH_HELP_HPP
#define BRANCH_HELP_HPP

#include <branch/base.hpp>

extern bool branch_help_predicate(const Flags& flags);
extern int branch_help_routine(const Flags& flags);

constexpr Branch get_branch_help(void) {
  return Branch(
    branch_help_predicate,
    branch_help_routine
  );
}

#endif // BRANCH_HELP_HPP
