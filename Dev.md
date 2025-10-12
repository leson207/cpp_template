bazel search for system lib if not found external lib

build --cxxopt=-Iexternal/boost+

https://bazel.build/versions/6.0.0/rules/lib/globals#archive_override

https://bazel.build/reference/be/c-cpp#cc_library




bazel_dep(name = "openssl", version = "3.6.0")
archive_override(
    module_name = "openssl",
    strip_prefix = "openssl-3.6.0",
    sha256 = "b6a5f44b7eb69e3fa35dbf15524405b44837a481d43d81daddde3ff21fcbb8e9",
    urls = ["https://github.com/openssl/openssl/releases/download/openssl-3.6.0/openssl-3.6.0.tar.gz"],
    patch_cmds = [
        """echo 'module(name = "openssl", version = "3.6.0")

bazel_dep(name = "rules_foreign_cc", version = "0.15.1")' > MODULE.bazel""",
        """cat > BUILD.bazel <<'EOF'
load("@rules_foreign_cc//foreign_cc:defs.bzl", "configure_make")

package(default_visibility = ["//visibility:public"])

filegroup(
    name = "all_srcs",
    srcs = glob(["**"]),
)

configure_make(
    name = "openssl",
    lib_source = ":all_srcs",
    out_static_libs = ["libcrypto.a", "libssl.a"],
    configure_command = "Configure",
    configure_options = [
        "no-asm",
        "no-shared",
        "--openssldir=/etc/ssl",
        "linux-x86_64"
    ],
    args = ["-j$(nproc)"],
    targets = [
        "install_sw",
    ],
    linkopts = ["-pthread"],
)
EOF
""",
    ],
)