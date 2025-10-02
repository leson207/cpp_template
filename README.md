# Install
```
conan profile detect --force # coppy content of this later

conan install . \
  --profile:host=./conan/profiles/release \
  --profile:build=./conan/profiles/release \
  --build=missing \
  --output-folder=./conan/build

```
# Notice
update cmake version
ctr+I have tab_size=2, use clang_tidy or format

# Reference
https://github.com/Kitware/CMake
https://cmake.org/cmake/help/book/mastering-cmake/chapter/Testing%20With%20CMake%20and%20CTest.html