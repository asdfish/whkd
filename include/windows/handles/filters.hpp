#ifndef HANDLE_FILTERS_HPP
#define HANDLE_FILTERS_HPP

#include <functional>

#include <windows.h>

extern std::function<bool (HWND)> handle_filter_winapi(BOOL (*predicate) (HWND));

#endif // HANDLE_FILTERS_HPP
