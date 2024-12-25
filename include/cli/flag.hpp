#ifndef FLAG_HPP
#define FLAG_HPP

#include <optional>
#include <string>

struct option;

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
  option get_option() const;
};

#endif // FLAG_HPP
