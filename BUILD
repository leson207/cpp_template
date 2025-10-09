load("@hedron_compile_commands//:refresh_compile_commands.bzl", "refresh_compile_commands")

refresh_compile_commands(
    name = "refresh_compile_commands",

    # Specify your target - simple string format works fine
    targets = ["//src:main"],

    # Optional: Exclude headers if you use ccls instead of clangd
    # exclude_headers = "all",

    # Optional: Exclude external dependencies for faster generation
    exclude_external_sources = True,
)
