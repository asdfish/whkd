#ifndef BRANCH_HPP
#define BRANCH_HPP

class Flags;

class Branch {
public:
  bool (*predicate) (const Flags&) = nullptr;
  int (*routine) (const Flags&) = nullptr;

  constexpr Branch(bool (*i_predicate) (const Flags&), int (*i_routine) (const Flags&)):
    predicate(i_predicate),
    routine(i_routine) {}
};

#endif // BRANCH_HPP
