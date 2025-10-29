#pragma once

#include "qlogicae_cli/utilities.hpp"
#include "qlogicae_cli/application.hpp"

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
