#include <branch/main.hpp>
#include <cli/flags.hpp>
#include <std/functional.hpp>
#include <windows/handles/filters.hpp>
#include <windows/handles/getters.hpp>
#include <windows/handles/maps.hpp>

#include <winuser.h>

#include <iostream>

int branch_main(const Flags&) {
  std::optional<std::vector<HWND>> handles = get_handles();

  filter<HWND>(*handles, handle_filter_winapi(IsWindowVisible));

  std::vector<std::optional<std::string>> texts
    = map<std::vector<HWND>::const_iterator, HWND, std::optional<std::string>>
    (handles->cbegin(), handles->cend(), handle_map_to_string);

  for(const auto& text : texts)
    if(text.has_value())
      std::cout << text.value() << '\n';
  return 0;
}
