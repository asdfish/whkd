#ifndef EVENT_HANDLER_HPP
#define EVENT_HANDLER_HPP

#include <windows.h>

class EventHandler {
public:
  EventHandler(int hook_type, HOOKPROC hook_callback);
  ~EventHandler(void);

private:
  HHOOK hook_handle = nullptr;
};

#endif // EVENT_HANDLER_HPP
