CXX ?= c++
override CXXFLAGS += -std=c++17
override CXXFLAGS += -Wall -Wextra -Wpedantic
override CXXFLAGS += -Ibuild -Iinclude
override CXXFLAGS += -DWHKD_VERSION='"0.1"'

define COMPILE
${CXX} -c ${1} ${CXXFLAGS} -o ${2}

endef
define REMOVE
$(if $(wildcard $(1)),$\
	rm $(1))

endef
define INHERIT_ENV_ARGUMENT
$(if $(1),-D$(1))
endef

PROCESSED_HEADERS := $(patsubst include/%.hpp,$\
										 	build/%.hpp.gch,$\
											$(shell find include -name '*.hpp'))
OBJECTS := $(patsubst src/%.cpp,$\
					 	build/%.o,$\
						$(shell find src -name '*.cpp'))
WHKD_REQUIREMENTS := ${PROCESSED_HEADERS} ${OBJECTS}

all: whkd.exe

build/%.gch: include/%
	$(call COMPILE,$<,$@)
build/%.o: src/%.cpp
	$(call COMPILE,$<,$@)
remove/%:
	$(call REMOVE,$(patsubst remove/%,%,$@))

whkd.exe: ${WHKD_REQUIREMENTS}
	${CXX} ${OBJECTS} ${CXXFLAGS} ${LDFLAGS} $(call INHERIT_ENV_ARGUMENT,MSYSTEM) -o $@

clean: $(patsubst %,remove/%,${WHKD_REQUIREMENTS} whkd.exe)

.PHONY: all clean remove/%
