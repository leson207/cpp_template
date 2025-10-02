# Install
```
conan profile detect --force # coppy content of this later

conan install . \
  --profile:host=conanprofile \
  --profile:build=conanprofile \
  --build=missing \
  --output-folder=conan

```
# Notice
update cmake version
ctr+I have tab_size=2, use clang_tidy or format
up-to-date conan profile
structure conan file into folder (where to put conanfile, profile, dep, ...)

# Reference
https://github.com/Kitware/CMake
https://cmake.org/cmake/help/book/mastering-cmake/chapter/Testing%20With%20CMake%20and%20CTest.html