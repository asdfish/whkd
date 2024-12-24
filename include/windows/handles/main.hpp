#ifndef HANDLES_MAIN_HPP
#define HANDLES_MAIN_HPP

#include <cstdlib>
#include <optional>
#include <vector>

#include <windows.h>

extern std::optional<std::vector<HWND>> get_handles(void);
extern std::optional<std::vector<HWND>> get_handles(HDESK desktop);

extern std::optional<std::size_t> get_handles_length(void);
extern std::optional<std::size_t> get_handles_length(HDESK desktop);

#endif // HANDLES_MAIN_HPP
