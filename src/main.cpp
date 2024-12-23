#include <windows/error.hpp>
#include <windows/handles/public.hpp>

#include <algorithm>
#include <iostream>

int main(void) {
  auto handles = get_handles();
  if(!handles.has_value())
    return -1;

  auto texts = get_handle_texts(handles.value());

  for(const auto& text : texts)
    if(text.has_value())
      std::cout << text.value() << '\n';

  return 0;
}
