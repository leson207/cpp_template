.ONESHELL:
SHELL := /bin/bash

.PHONY:

PRESET ?= debug

CONAN_ENV := ./conan/build/Debug/generators/conanbuild.sh

cmake_config:
	. $(CONAN_ENV)
	cmake --preset $(PRESET)

cmake_build:
	. $(CONAN_ENV)
	cmake --build --preset $(PRESET)

run:
	. $(CONAN_ENV)
	./build/$(PRESET)/src/main

cmake_clean:
	rm -rf ./build/$(PRESET)

conan_build:
	conan install . \
		--profile:host=conan/profiles/$(PRESET) \
		--profile:build=conan/profiles/$(PRESET) \
		--build=missing \
		--output-folder=conan
	rm CMakeUserPresets.json

conan_clean:
	rm -rf conan/build