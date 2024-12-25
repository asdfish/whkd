#ifndef HANDLE_FILTERS_HPP
#define HANDLE_FILTERS_HPP

#include <windows.h>

#include <functional>

extern std::function<bool (HWND)> handle_filter_winapi(BOOL (*predicate) (HWND));

#endif // HANDLE_FILTERS_HPP
