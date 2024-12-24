#ifndef HANDLES_GETTERS_HPP
#define HANDLES_GETTERS_HPP

#include <cstdlib>
#include <optional>
#include <vector>

#include <windows.h>

extern std::optional<std::vector<HWND>> get_handles(void);
extern std::optional<std::size_t> get_handles_length(void);

#endif // HANDLES_GETTERS_HPP
