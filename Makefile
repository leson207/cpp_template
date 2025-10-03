.PHONY: build run clean conan

PRESET ?= debug

configure:
	cmake --preset $(PRESET)

build: configure
	cmake --build --preset $(PRESET)

run:
	./build/$(PRESET)/src/main

clean:
	rm -rf ./build/$(PRESET)

conan_build:
	conan install . --profile:host=conan/profiles/$(PRESET) --profile:build=conan/profiles/$(PRESET) --build=missing --output-folder=conan
	rm CMakeUserPresets.json
	source conan/build/Debug/generators/conanbuild.sh

conan_clean:
	rm -rf conan/build