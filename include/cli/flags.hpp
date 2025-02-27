#ifndef FLAGS_HPP
#define FLAGS_HPP

#include <string>
#include <vector>
#include <unordered_map>

class Flag;
struct option;

class Flags {
public:
  std::unordered_map<char, Flag> flags;

  Flags(std::unordered_map<char, Flag>&& i_flags);
  const Flag& operator[](char key) const;
  void parse(int argc, char* argv[]);
  void print_documentation(std::size_t padding) const;

private:
  std::vector<option> get_options() const;
  std::string get_option_string(void) const;
  static std::string get_padding(std::size_t padding);
  std::size_t get_max_name_length(void) const;
};

#endif // FLAGS_HPP
