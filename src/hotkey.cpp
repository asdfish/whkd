#include <hotkey.hpp>
#include <macros.hpp>

#include <utility>

Hotkey::Hotkey(const char* i_command, std::vector<DWORD>&& i_keys):
  command(i_command),
  keys(std::move(i_keys)) {}
InputsStatus Hotkey::get_inputs_status(const std::vector<DWORD>& inputs) const {
  bool match = true;

  InputsStatus status = INPUTS_MATCH;
  if(inputs.size() < keys.size())
    status = INPUTS_CONTAIN;
  else if(inputs.size() > keys.size())
    match = false;

  for(size_t i = 0; i < MIN(inputs.size(), keys.size()) && match; i ++)
    match = inputs[i] == keys[i];

  if(match)
    return status;
  else
    return INPUTS_NO_MATCH;
}
void Hotkey::execute(void) const {
  STARTUPINFO startup_information;
  ZeroMemory(&startup_information, sizeof(startup_information));
  startup_information.cb = sizeof(startup_information);

  PROCESS_INFORMATION process_information;

  CreateProcessA(
    nullptr,
    (LPSTR) command,
    NULL,
    NULL,
    FALSE,
    0,
    NULL,
    NULL,
    &startup_information,
    &process_information
  );
}
