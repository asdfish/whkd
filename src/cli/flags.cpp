#include <cli/flags.hpp>
#include <std/functional.hpp>
#include <std/unordered_map.hpp>

#include <utility>

Flags::Flags(std::unordered_map<char, Flag>&& i_flags):
  flags(std::move(i_flags)) {}
const Flag& Flags::operator[](char key) const {
  return flags.at(key);
}
std::vector<option> Flags::get_options() const {
  using iterator_t = std::unordered_map<char, Flag>::const_iterator;
  using output_t = option;

  std::vector<output_t> output;
  output.reserve(flags.size() + 1);

  map<iterator_t, output_t>(flags.cbegin(), flags.cend(), output, [](const iterator_t& flag) -> output_t {
    option output = flag->second.get_option();
    output.val = flag->first;

    return output;
  });

  output.push_back(option { 0, 0, 0, 0 });
  return output;
}
std::string Flags::get_option_string(void) const {
  std::string output;
  output.reserve(flags.size() * 2);

  for(const auto& flag : flags) {
    output += flag.first;
    if(flag.second.argument_type != ARGUMENT_NONE)
      output += ':';
  }

  return output;
}
void Flags::parse(int argc, char* argv[]) {
  std::vector<option> options = get_options();
  std::string option_string = get_option_string();

  int option_character = -1;
  int option_index = 0;
  while((option_character = getopt_long(argc, argv, option_string.c_str(), &options[0], &option_index)) != -1) {
    if(unordered_map_contains<char, Flag>(flags, option_character)) {
      Flag& flag = flags.at(option_character);

      switch(flag.argument_type) {
        case ARGUMENT_REQUIRED:
        case ARGUMENT_OPTIONAL:
          flag.argument = optarg;
        default:
          flag.set = true;
          break;
      }
    }
  }
}
