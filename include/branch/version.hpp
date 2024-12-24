#ifndef BRANCH_VERSION_HPP
#define BRANCH_VERSION_HPP

#include <branch/base.hpp>

extern bool branch_version_predicate(const Flags& flags);
extern int branch_version_routine(const Flags& flags);

constexpr BranchBase get_branch_version(void) {
  return BranchBase(
    branch_version_predicate,
    branch_version_routine
  );
}

#endif // BRANCH_VERSION_HPP
