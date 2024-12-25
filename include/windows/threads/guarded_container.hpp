#ifndef GUARDED_CONTAINER_HPP
#define GUARDED_CONTAINER_HPP

#include <windows.h>

#include <vector>

template <typename T>
class GuardedContainer {
  T data;
public:
  CRITICAL_SECTION* critical_section = nullptr;

  GuardedContainer(void);
  GuardedContainer(CRITICAL_SECTION* i_critical_section);
  bool modify(bool (*callback) (T& data, void* user_data), void* user_data);
  const T& read(void) const;
};

extern template class GuardedContainer<std::vector<DWORD>>;

#endif // GUARDED_CONTAINER_HPP
