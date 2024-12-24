#include <cli/flags.hpp>
#include <branch/base.hpp>
#include <branch/help.hpp>

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

int main(int argc, char* argv[]) {
  Flags flags = Flags({
    { 'h', Flag(ARGUMENT_NONE, "help") },
    { 'v', Flag(ARGUMENT_NONE, "version") },
  });
  flags.parse(argc, argv);

  static constexpr BranchBase branchs[] = {
    get_branch_help(),
  };
  for(size_t i = 0; i < ARRAY_LENGTH(branchs); i ++)
    if(branchs[i].predicate(flags))
      return branchs[i].routine(flags);

  return 0;
}
