CXX ?= c++
override CXXFLAGS += -std=c++17
override CXXFLAGS += -Wall -Wextra -Wpedantic
override CXXFLAGS += -Ibuild -Iinclude

define COMPILE
${CXX} -c ${1} ${CXXFLAGS} -o ${2}

endef
define REMOVE
$(if $(wildcard $(1)),$\
	rm $(1))

endef

PROCESSED_HEADERS := $(patsubst include/%.hpp,$\
										 	build/%.hpp.gch,$\
											$(shell find include -name '*.hpp'))
OBJECTS := $(patsubst src/%.cpp,$\
					 	build/%.o,$\
						$(shell find src -name '*.cpp'))
WWM_REQUIREMENTS := ${PROCESSED_HEADERS} ${OBJECTS}

all: wwm.exe

build/%.gch: include/%
	$(call COMPILE,$<,$@)
build/%.o: src/%.cpp
	$(call COMPILE,$<,$@)

wwm.exe: ${WWM_REQUIREMENTS}
	${CXX} ${OBJECTS} ${CXXFLAGS} ${LDFLAGS} -o $@

clean:
	$(foreach ITEM,$\
		${WWM_REQUIREMENTS} wwm.exe,$\
		$(call REMOVE,${ITEM}))

.PHONY: all clean
