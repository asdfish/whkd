#ifndef KEY_BINDING_HPP
#define KEY_BINDING_HPP

#include <config/keys/action/base.hpp>
#include <config/keys/target/base.hpp>

#include <memory>

class KeyBinding {
  std::vector<DWORD> keys;
  std::unique_ptr<KeyActionBase> action;
};

#endif // KEY_BINDING_HPP
