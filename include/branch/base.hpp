#ifndef BRANCH_HPP
#define BRANCH_HPP

class Branch {
public:
  bool (*predicate) (void) = nullptr;
  int (*routine) (void) = nullptr;

  constexpr Branch(bool (*i_predicate) (void), int (*i_routine) (void)):
    predicate(i_predicate),
    routine(i_routine) {}
};

#endif // BRANCH_HPP
