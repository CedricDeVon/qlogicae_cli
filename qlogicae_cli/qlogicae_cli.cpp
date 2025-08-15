#pragma once

#include "qlogicae_cli.hpp"

int main(int argc, char** argv)
{
    QLogicaeCLI::QLogicaeCLIApplication& cli_application =
        QLogicaeCLI::QLogicaeCLIApplication::get_instance();

    const bool is_setup_successful = cli_application.setup(argc, argv);
    if (!is_setup_successful)
    {
        return EXIT_FAILURE;
    }

    return (cli_application.parse()) ? EXIT_SUCCESS : EXIT_FAILURE;
}
