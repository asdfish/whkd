#include <windows/threads/critical_section_guard.hpp>
#include <windows/threads/guarded_container.hpp>

#include <exception>
#include <optional>
#include <utility>

template <typename T>
GuardedContainer<T>::GuardedContainer(void) {
  InitializeCriticalSection(&critical_section);
}
template <typename T>
GuardedContainer<T>::GuardedContainer(T&& i_data):
  data(std::move(i_data)) {
  InitializeCriticalSection(&critical_section);
}
template <typename T>
GuardedContainer<T>::~GuardedContainer(void) {
  DeleteCriticalSection(&critical_section);
}

template <typename T>
template <typename UT>
void GuardedContainer<T>::read(void (*callback) (const T& data, UT& user_data), UT& user_data) {
  std::optional<CriticalSectionGuard> critical_section_guard = std::nullopt;
  if(writing.load())
    critical_section_guard.emplace(CriticalSectionGuard(&critical_section));

  callback(data, user_data);
}
template <typename T>
template <typename UT>
void GuardedContainer<T>::write(void (*callback) (T& data, UT& user_data), UT& user_data) {
  CriticalSectionGuard critical_section_guard(&critical_section);

  writing.store(true);
  try {
    callback(data, user_data);

    writing.store(false);
  } catch(...) {
    writing.store(false);

    std::exception_ptr current_exception = std::current_exception();
    std::rethrow_exception(current_exception);
  }
}

template class GuardedContainer<std::vector<DWORD>>;
