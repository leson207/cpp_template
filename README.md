# Install
## Conan
```
# create conan default profile
conan profile detect --force # coppy content of this later the use make
```

## CLangd
ctr + shift + p -> Open Workspace Setting
or .clangd file
## Linter
Add .clang-tidy file, vscode auto detect that file

## Formater
add .clang-format, vscode auto detect that file

use find_package to add lib or clangd will use system lib
# Notice
python file for conan
update cmake version
# Reference
https://github.com/Kitware/CMake
https://cmake.org/cmake/help/book/mastering-cmake/chapter/Testing%20With%20CMake%20and%20CTest.html
https://marketplace.visualstudio.com/items?itemName=llvm-vs-code-extensions.vscode-clangd