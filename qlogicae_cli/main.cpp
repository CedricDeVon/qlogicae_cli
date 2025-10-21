#include "pch.hpp"

#include "main.hpp"

int main(int argc, char** argv)
{
    QLogicaeCLI::UTILITIES.setup();
    QLogicaeCLI::Application& cli_application =
        QLogicaeCLI::Application::get_instance();

    const bool is_setup_successful = cli_application.setup(argc, argv);
    if (!is_setup_successful)
    {
        return EXIT_FAILURE;
    }

    return (cli_application.parse()) ? EXIT_SUCCESS : EXIT_FAILURE;
}
