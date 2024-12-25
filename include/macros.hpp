#ifndef MACROS_HPP
#define MACROS_HPP

#include <iostream>

#define LOG(FLAGS, MESSAGE) \
  if(FLAGS['l'].set) \
    std::cout << MESSAGE << '\n'

#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))

#endif // MACROS_HPP
