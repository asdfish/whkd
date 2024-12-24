#ifndef BRANCH_WWM_HPP
#define BRANCH_WWM_HPP

#include <branch/base.hpp>

extern bool branch_wwm_predicate(const Flags& flags);
extern int branch_wwm_routine(const Flags& flags);

constexpr BranchBase get_branch_wwm(void) {
  return BranchBase(
    branch_wwm_predicate,
    branch_wwm_routine
  );
}

#endif // BRANCH_WWM_HPP
