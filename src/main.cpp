#include <std_ex/unistd.hpp>
#include <iostream>
#include <thread>
int main(void) {
  const char* file = R"(C:\msys64\usr\bin\ls.exe)";
  const char* argv[] = {R"(C:\msys64\usr\bin\ls.exe)", "-lsh", nullptr };

  std::thread exec_thread([=] {
    execv(file, (char* const*) argv);
  });
  exec_thread.join();

  std::cout << "after";
  return 0;
}

/*#include <command/timed.hpp>*/
/*int main(void) {*/
/*  CommandTimed ct("find /", 1);*/
/*  ct.execute();*/
/*  return 0;*/
/*}*/

/*#include <cli/flag.hpp>*/
/*#include <cli/flags.hpp>*/
/*#include <branch/base.hpp>*/
/*#include <branch/help.hpp>*/
/*#include <branch/main.hpp>*/
/*#include <branch/version.hpp>*/
/**/
/*#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))*/
/**/
/*int main(int argc, char* argv[]) {*/
/*  Flags flags = Flags({*/
/*    { 'h', Flag(ARGUMENT_NONE, "help",    "Print this message and exit") },*/
/*    { 'v', Flag(ARGUMENT_NONE, "version", "Print version information and exit") },*/
/**/
/*    { 'l', Flag(ARGUMENT_NONE, "log",     "Enable logging") }*/
/*  });*/
/*  flags.parse(argc, argv);*/
/**/
/*  constexpr Branch branches[] = {*/
/*    get_branch_help(),*/
/*    get_branch_version(),*/
/*  };*/
/*  for(std::size_t i = 0; i < ARRAY_LENGTH(branches); i ++)*/
/*    if(branches[i].predicate(flags))*/
/*      return branches[i].routine(flags);*/
/**/
/*  return branch_main(flags);*/
/*}*/
