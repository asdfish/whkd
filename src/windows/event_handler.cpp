#include <windows/event_handler.hpp>

EventHandler::EventHandler(int hook_type, HOOKPROC hook_callback) {
  hook_handle = SetWindowsHookExA(hook_type, hook_callback, NULL, 0);
}
EventHandler::~EventHandler(void) {
  if(hook_handle)
    UnhookWindowsHookEx(hook_handle);
}
