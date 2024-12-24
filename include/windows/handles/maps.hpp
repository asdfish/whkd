#ifndef HANDLE_MAPS_HPP
#define HANDLE_MAPS_HPP

#include <windows.h>

#include <string>
#include <optional>

extern std::optional<std::string> handle_map_to_string(const HWND& handle);
extern std::optional<RECT> handle_map_to_rect(const HWND& handle);

#endif // HANDLE_MAPS_HPP
