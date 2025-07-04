#pragma once

#include "qlogicae_cli.hpp"

int main(int argc, char** argv)
{
    const bool is_setup_successful =
        QLogicaeCLI::QLogicaeCLIApplication::get_instance().setup(argc, argv);
    if (!is_setup_successful)
    {
        return EXIT_FAILURE;
    }

    return (QLogicaeCLI::QLogicaeCLIApplication::get_instance().parse()) ?
        EXIT_SUCCESS : EXIT_FAILURE;
}
