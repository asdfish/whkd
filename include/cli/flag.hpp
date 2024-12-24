#ifndef FLAG_HPP
#define FLAG_HPP

#include <getopt.h>

#include <optional>
#include <string>

enum ArgumentType {
  ARGUMENT_NONE = 0,
  ARGUMENT_REQUIRED = 1,
  ARGUMENT_OPTIONAL = 2,
};

class Flag {
public:
  ArgumentType argument_type;
  std::string name;

  std::optional<std::string> documentation;

  bool set = false;
  std::optional<std::string> argument = std::nullopt;

  Flag(ArgumentType i_argument_type, std::string&& i_name, std::optional<std::string>&& i_documentation);
  constexpr option get_option() const {
    return option { name.c_str(), argument_type, nullptr, 0 };
  }
};

#endif // FLAG_HPP
