#include <cli/flag.hpp>

Flag::Flag(ArgumentType i_argument_type, std::string&& i_name):
  argument_type(i_argument_type),
  name(std::move(i_name)),

  set(false),
  argument(std::nullopt) {}
