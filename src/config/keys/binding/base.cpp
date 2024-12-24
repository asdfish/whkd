#include <config/keys/binding/base.hpp>

#include <utility>

KeyBinding::KeyBinding(std::vector<DWORD>&& i_keys, std::unique_ptr<KeyActionBase>&& i_action, std::unique_ptr<KeyTargetBase>&& i_targets):
  keys(std::move(i_keys)),
  action(std::move(i_action)),
  targets(std::move(i_targets)) {}
