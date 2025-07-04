#pragma once

#include "erwin_cli.hpp"

int main(int argc, char** argv)
{
    const bool is_setup_successful =
        ErwinCLI::ErwinCLIApplication::get_instance().setup(argc, argv);
    if (!is_setup_successful)
    {
        return EXIT_FAILURE;
    }

    return (ErwinCLI::ErwinCLIApplication::get_instance().parse()) ?
        EXIT_SUCCESS : EXIT_FAILURE;
}
