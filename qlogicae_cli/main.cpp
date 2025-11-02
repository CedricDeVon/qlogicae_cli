#include "pch.hpp"

#include "main.hpp"

int main(int argc, char** argv)
{
    try
    {   
        bool is_safe = QLogicaeCLI::APPLICATION.setup(argc, argv);
        if (!is_safe)
        {
            QLogicaeCore::LOGGER.handle_exception(
                "main()",
                "Setup failed"
            );

            return EXIT_FAILURE;
        }

        is_safe = QLogicaeCLI::APPLICATION.parse();
        if (!is_safe)
        {
            QLogicaeCore::LOGGER.handle_exception(
                "main()",
                "Parsing failed"
            );

            return EXIT_FAILURE;
        }

        is_safe = QLogicaeCLI::APPLICATION.terminate();
        if (!is_safe)
        {
            QLogicaeCore::LOGGER.handle_exception(
                "main()",
                "Termination failed"
            );

            return EXIT_FAILURE;
        }

        return EXIT_SUCCESS;
    }
    catch (const std::exception& exception)
    {
        QLogicaeCore::LOGGER.handle_exception(
            "main()",
            exception.what()
        );

        return EXIT_FAILURE;
    }
}

namespace QLogicaeCLI
{

}
