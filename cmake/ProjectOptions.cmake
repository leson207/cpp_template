add_library(project_options INTERFACE)

target_compile_features(project_options INTERFACE cxx_std_23)

# ---- warnings & base flags ----
target_compile_options(project_options INTERFACE
  -Wall -Wextra -Wpedantic -pipe -march=native
  -fstack-protector-strong
  -fno-common

  $<$<CXX_COMPILER_ID:GNU>:-fdiagnostics-color=auto>
  $<$<CXX_COMPILER_ID:Clang>:-fdiagnostics-color=always>

  $<$<CONFIG:Debug>:-Werror -O0 -g -fno-omit-frame-pointer>
  $<$<CONFIG:Release>:-O3 -DNDEBUG>
)

# ---- clang-only enhancements ----
target_compile_options(project_options INTERFACE
  $<$<CXX_COMPILER_ID:Clang>:-fconstexpr-steps=2147483647>
  $<$<AND:$<CONFIG:Debug>,$<CXX_COMPILER_ID:Clang>>:-glldb>
)

# ---- linker hardening ----
target_link_options(project_options INTERFACE
  -Wl,-z,relro,-z,now

  $<$<CONFIG:Debug>:-Wl,-O1,--as-needed>
)

# ---- global properties ----
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_VISIBILITY_INLINES_HIDDEN ON)

