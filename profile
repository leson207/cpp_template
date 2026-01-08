[settings]
os=Linux
arch=x86_64
compiler=clang
compiler.version=20
compiler.cppstd=23
compiler.libcxx=libc++

[conf]
tools.cmake.cmaketoolchain:generator=Ninja
tools.compilation:verbosity=verbose

[buildenv]
CC=clang
CXX=clang++
LD=mold
