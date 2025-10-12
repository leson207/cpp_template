.PHONY: build

build:
	bazel build //src:main --config=dbg --keep_going

refresh:
	bazel run //:refresh_compile_commands --config=dbg

run:
	./bazel-bin/src/main
