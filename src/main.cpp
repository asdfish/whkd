#include <branch/base.hpp>
#include <branch/help.hpp>
#include <branch/main.hpp>
#include <branch/version.hpp>
#include <cli/flag.hpp>
#include <cli/flags.hpp>

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

int main(int argc, char* argv[]) {
  Flags flags = Flags({
    { 'h', Flag(ARGUMENT_NONE, "help",    "Print this message and exit") },
    { 'v', Flag(ARGUMENT_NONE, "version", "Print version information and exit") },

    { 'l', Flag(ARGUMENT_NONE, "log",     "Enable logging") }
  });
  flags.parse(argc, argv);

  constexpr Branch branches[] = {
    get_branch_help(),
    get_branch_version(),
  };
  for(std::size_t i = 0; i < ARRAY_LENGTH(branches); i ++)
    if(branches[i].predicate(flags))
      return branches[i].routine(flags);

  return branch_main(flags);
}
