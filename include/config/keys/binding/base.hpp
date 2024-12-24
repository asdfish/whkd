#ifndef KEY_BINDING_HPP
#define KEY_BINDING_HPP

#include <config/keys/action/base.hpp>
#include <config/keys/target/base.hpp>

#include <memory>

class KeyBinding {
  std::vector<DWORD> keys;
  std::unique_ptr<KeyActionBase> action;
  std::unique_ptr<KeyTargetBase> targets;

public:
  KeyBinding(std::vector<DWORD>&& i_keys, std::unique_ptr<KeyActionBase>&& i_action, std::unique_ptr<KeyTargetBase>&& i_targets);
};

#endif // KEY_BINDING_HPP
