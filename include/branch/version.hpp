#ifndef BRANCH_VERSION_HPP
#define BRANCH_VERSION_HPP

#include <branch/base.hpp>

extern bool branch_version_predicate(void);
extern int branch_version_routine(void);

constexpr Branch get_branch_version(void) {
  return Branch(
    branch_version_predicate,
    branch_version_routine
  );
}

#endif // BRANCH_VERSION_HPP
