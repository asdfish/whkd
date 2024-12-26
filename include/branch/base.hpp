#ifndef BRANCH_HPP
#define BRANCH_HPP

class Flags;

class Branch {
public:
  bool (*predicate) (const Flags& flags) = nullptr;
  int (*routine) (const Flags& flags) = nullptr;

  constexpr Branch(bool (*i_predicate) (const Flags& flags), int (*i_routine) (const Flags& flags)):
    predicate(i_predicate),
    routine(i_routine) {}
};

#endif // BRANCH_HPP
