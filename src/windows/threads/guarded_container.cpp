#include <windows/threads/guarded_container.hpp>

template <typename T>
GuardedContainer<T>::GuardedContainer(void) {}
template <typename T>
GuardedContainer<T>::GuardedContainer(CRITICAL_SECTION* i_critical_section):
  critical_section(i_critical_section) {}
template <typename T>
bool GuardedContainer<T>::modify(bool (*callback) (T& data, void* user_data), void* user_data) {
  if(!critical_section)
    return false;

  CriticalSectionGuard section_guard(critical_section);
  return callback(data, user_data);
}
template <typename T>
const T& GuardedContainer<T>::read(void) const {
  return data;
}

template class GuardedContainer<std::vector<DWORD>>;
