#include <config/main.hpp>

#include <utility>

Config::Config(std::vector<KeyBinding>&& i_key_bindings):
  key_bindings(std::move(i_key_bindings)) {}

/*Config get_config(void) {*/
/*  return Config({*/
/*    KeyBinding(*/
/*      std::make_unique<>*/
/*    ),*/
/*  });*/
/*}*/
