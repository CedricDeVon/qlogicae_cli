#pragma once

#include "qlogicae_cli/includes/utilities.hpp"
#include "qlogicae_cli/includes/application.hpp"

int main(int, char**);

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE,
    LPSTR,
    int
)
{
    return main(__argc, __argv);
}

namespace QLogicaeCLI
{

}

