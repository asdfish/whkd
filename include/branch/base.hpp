#ifndef BRANCH_HPP
#define BRANCH_HPP

class Flags;

typedef bool (*branch_predicate_t) (const Flags&);
typedef int (*branch_routine_t) (const Flags&);

class Branch {
public:
  branch_predicate_t predicate = nullptr;
  branch_routine_t routine = nullptr;

  constexpr Branch(branch_predicate_t i_predicate, branch_routine_t i_routine):
    predicate(i_predicate),
    routine(i_routine) {}
};

#endif // BRANCH_HPP
