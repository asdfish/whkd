#ifndef HANDLES_PUBLIC_HPP
#define HANDLES_PUBLIC_HPP

#include <cstdlib>
#include <optional>
#include <vector>

#include <windows.h>

extern std::optional<std::vector<HWND>> get_handles(void);
extern std::optional<std::vector<HWND>> get_handles(HDESK desktop);

extern std::optional<std::size_t> get_handles_length(void);
extern std::optional<std::size_t> get_handles_length(HDESK desktop);

extern std::vector<std::optional<std::string>> get_handle_texts(const std::vector<HWND>& handles);

#endif // HANDLES_PUBLIC_HPP
