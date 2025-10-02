.PHONY: build run clean conan

PRESET ?= debug

configure:
	cmake --preset $(PRESET)

build: configure
	cmake --build --preset $(PRESET)

run: build
	./build/$(PRESET)/src/main

clean:
	rm -rf ./build/$(PRESET)

conan:
	conan install . --profile:host=conan/profiles/$(PRESET) --profile:build=conan/profiles/$(PRESET) --build=missing --output-folder=conan
	rm CMakeUserPresets.json

clean_conan:
	rm -rf conan/build