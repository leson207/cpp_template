# Install
```
conan profile detect --force # coppy content of this later

conan install . \
  --profile:host=profiles/debug \
  --profile:build=profiles/debug \
  --build=missing \
  --output-folder=build/debug/conan

```
# Notice
update cmake version
ctr+I have tab_size=2, use clang_tidy or format

# Reference
https://github.com/Kitware/CMake
https://cmake.org/cmake/help/book/mastering-cmake/chapter/Testing%20With%20CMake%20and%20CTest.html