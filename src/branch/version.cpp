#ifndef WWM_VERSION
#error "WWM_VERSION not defined, please compile with -DWWM_VERSION='\"MAJOR.MINOR\"'"
#endif

#include <branch/version.hpp>
#include <cli/flag.hpp>
#include <cli/flags.hpp>

#include <iostream>

bool branch_version_predicate(const Flags& flags) {
  return flags['v'].set;
}
int branch_version_routine(const Flags&) {
  std::cout << "wwm " << WWM_VERSION << "\n"
    "Copyright (C) 2024 asdfish\n"
    "License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.\n"
    "This is free software: you are free to change and redistribute it.\n"
    "There is NO WARRANTY, to the extent permitted by law.\n";
  return 0;
}
