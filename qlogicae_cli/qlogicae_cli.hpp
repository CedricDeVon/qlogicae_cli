#pragma once

#include "utilities.hpp"
#include "application.hpp"

int main(int, char**);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int)
{
    return main(__argc, __argv);
}
