.ONESHELL:
SHELL := /bin/bash

.PHONY:

PRESET ?= Debug

CONAN_ENV := ./build/${PRESET}/generators/conanbuild.sh

cmake_config:
	. $(CONAN_ENV)
	cmake --preset $(PRESET)

cmake_build:
	. $(CONAN_ENV)
	cmake --build --preset $(PRESET)

run:
	./build/$(PRESET)/main

test:
	. $(CONAN_ENV)
	ctest --test-dir build/Debug --output-on-failure

cmake_clean:
	shopt -s extglob
	rm -rf ./build/$(PRESET)/!(generators)

conan_install:
	conan install . \
		--profile:host=profile \
		--profile:build=profile \
		--build=missing \
		-s build_type=$(PRESET)

	rm CMakeUserPresets.json

conan_clean:
	rm -rf ./build/$(PRESET)/generators

clean:
	rm -rf build/$(PRESET)