#ifndef FLAGS_HPP
#define FLAGS_HPP

#include <cli/flag.hpp>

#include <getopt.h>

#include <vector>
#include <unordered_map>

class Flags {
public:
  std::unordered_map<char, Flag> flags;

  Flags(std::unordered_map<char, Flag>&& i_flags);
  const Flag& operator[](char key) const;
  std::vector<option> get_options() const;
  std::string get_option_string(void) const;
  void parse(int argc, char* argv[]);
};

#endif // FLAGS_HPP
