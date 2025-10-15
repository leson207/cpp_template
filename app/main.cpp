#include "project/logger.hpp"

#include <CLI/CLI.hpp>

#include <iostream>

auto parse_args(int argc, char* argv[]) -> void
{
    CLI::App app{"This is my app!"};
    argv = app.ensure_utf8(argv);

    std::string foo{"Hello"};
    std::string bar{"world!"};

    app.add_option("--foo", foo, "Foo");
    app.add_option("--bar", bar, "Bar");

    app.parse(argc, argv);

    std::cout << foo << " " << bar << "\n";
}

auto main(int argc, char* argv[]) -> int
{
    get_logger();
    parse_args(argc, argv);
    return 0;
}