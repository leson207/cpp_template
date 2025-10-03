# Install
```
conan profile detect --force # coppy content of this later

ctr + shift + p -> Open Workspace Setting

"clangd.path": "/usr/bin/clangd-16",
"clangd.arguments": [
  "--compile-commands-dir=build",
  "--background-index",
  "--header-insertion=never"
]

```

use find_package to add lib or clangd will use system lib
# Notice
update cmake version
ctr+I have tab_size=2, use clang_tidy or format
# Reference
https://github.com/Kitware/CMake
https://cmake.org/cmake/help/book/mastering-cmake/chapter/Testing%20With%20CMake%20and%20CTest.html