#include <cli/flags.hpp>
#include <branch/base.hpp>
#include <branch/help.hpp>
#include <branch/version.hpp>
#include <branch/wwm.hpp>

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

int main(int argc, char* argv[]) {
  Flags flags = Flags({
    { 'h', Flag(ARGUMENT_NONE, "help",    "Print this message and exit") },
    { 'v', Flag(ARGUMENT_NONE, "version", "Print version information and exit") },
  });
  flags.parse(argc, argv);

  static constexpr BranchBase branchs[] = {
    get_branch_help(),
    get_branch_version(),
    get_branch_wwm(),
  };
  for(std::size_t i = 0; i < ARRAY_LENGTH(branchs); i ++)
    if(branchs[i].predicate(flags))
      return branchs[i].routine(flags);

  return 0;
}
