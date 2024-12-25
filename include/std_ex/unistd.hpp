#ifndef UNISTD_HPP
#define UNISTD_HPP

#ifdef MSYSTEM
#include <unistd.h>
#elif defined(__WIN32) || defined(WIN32)
#include <process.h>
#define execl _execv
#endif

#endif // UNISTD_HPP
