.PHONY: build run

PRESET ?= debug

configure:
	cmake --preset $(PRESET)

build: configure
	cmake --build --preset $(PRESET)

run: build
	./build/$(PRESET)/src/main
