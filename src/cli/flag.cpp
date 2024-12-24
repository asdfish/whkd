#include <cli/flag.hpp>

Flag::Flag(ArgumentType i_argument_type, std::string&& i_name, std::optional<std::string>&& i_documentation):
  argument_type(i_argument_type),
  name(std::move(i_name)),

  documentation(std::move(i_documentation)),

  set(false),
  argument(std::nullopt) {}
