#ifndef GUARDED_CONTAINER_HPP
#define GUARDED_CONTAINER_HPP

#include <windows.h>

#include <atomic>
#include <vector>

template <typename T>
class GuardedContainer {
  T data;

  CRITICAL_SECTION critical_section;
  std::atomic<bool> writing = false;

public:
  GuardedContainer(void);
  GuardedContainer(T&& i_data);
  ~GuardedContainer(void);

  template <typename UT>
  void read(void (*callback) (const T& data, UT& user_data), UT& user_data);

  template <typename UT>
  void write(void (*callback) (T& data, UT& user_data), UT& user_data);
};

extern template class GuardedContainer<std::vector<DWORD>>;
extern template void GuardedContainer<std::vector<DWORD>>::read<KBDLLHOOKSTRUCT*>(void (*callback) (const std::vector<DWORD>&, KBDLLHOOKSTRUCT*&), KBDLLHOOKSTRUCT*&);
extern template void GuardedContainer<std::vector<DWORD>>::write<KBDLLHOOKSTRUCT*>(void (*callback) (std::vector<DWORD>&, KBDLLHOOKSTRUCT*&), KBDLLHOOKSTRUCT*&);

#endif // GUARDED_CONTAINER_HPP
