.PHONY: build refresh clean

build:
	bazel build //src:main --config=dbg # opt, fastbuild

refresh:
	bazel run //:refresh_compile_commands

clean:
	bazel clean

run:
	./bazel-bin/src/main

lint:
	clang-tidy src/main.cc --export-fixes=fixes.yaml -p .
