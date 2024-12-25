#include <cli/flag.hpp>

#include <getopt.h>

Flag::Flag(ArgumentType i_argument_type, std::string&& i_name, std::optional<std::string>&& i_documentation):
  argument_type(i_argument_type),
  name(std::move(i_name)),

  documentation(std::move(i_documentation)),

  set(false),
  argument(std::nullopt) {}
option Flag::get_option() const {
  return option { name.c_str(), argument_type, nullptr, 0 };
}
