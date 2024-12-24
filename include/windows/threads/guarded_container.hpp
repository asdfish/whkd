#ifndef GUARDED_CONTAINER_HPP
#define GUARDED_CONTAINER_HPP

#include <windows/threads/critical_section_guard.hpp>

template <typename T>
class GuardedContainer {
  T data;
public:
  CRITICAL_SECTION* critical_section = nullptr;

  GuardedContainer(void) {}
  GuardedContainer(CRITICAL_SECTION* i_critical_section):
    critical_section(i_critical_section) {}

  // returns success && callback return
  bool modify(bool (*callback) (T& data, void* user_data), void* user_data) {
    if(!critical_section)
      return false;
    
    CriticalSectionGuard section_guard(critical_section);
    return callback(data, user_data);
  }
  const T& read(void) const {
    return data;
  }
};

#endif // GUARDED_CONTAINER_HPP
