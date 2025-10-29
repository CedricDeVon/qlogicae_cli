#include "pch.hpp"

#include "main.hpp"

int main(int argc, char** argv)
{
    try
    {        
        QLogicaeCLI::Application& cli_application =
            QLogicaeCLI::Application::get_instance();

        const bool is_setup_successful =
            cli_application.setup(
                argc,
                argv
            );
        if (!is_setup_successful)
        {
            QLogicaeCore::LOGGER.handle_exception_async(
                "main()",
                "Setup failed"
            );

            return EXIT_FAILURE;
        }

        const bool cli_application_parse_result = (cli_application.parse()) ?
            EXIT_SUCCESS :
            EXIT_FAILURE;        
        QLogicaeCore::UTILITIES.BOOST_ASIO_POOL.join();

        return cli_application_parse_result;
    }
    catch (const std::exception& exception)
    {
        QLogicaeCore::LOGGER.handle_exception_async(
            "main()",
            exception.what()
        );

        return EXIT_FAILURE;
    }
}
