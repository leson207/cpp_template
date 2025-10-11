.PHONY: build

build:
	bazel build //src:main --config=dbg

refresh:
	bazel run //:refresh_compile_commands

run:
	./bazel-bin/src/main
