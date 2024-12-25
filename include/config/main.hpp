#ifndef CONFIG_MAIN_HPP
#define CONFIG_MAIN_HPP

#include <vector>

class KeyBinding;

class Config {
  std::vector<KeyBinding> key_bindings;

public:
  Config(std::vector<KeyBinding>&& i_key_bindings);
};

extern Config get_config(void);

#endif // CONFIG_MAIN_HPP
