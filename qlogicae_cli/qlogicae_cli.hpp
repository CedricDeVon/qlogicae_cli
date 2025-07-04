#pragma once

#include "pch.hpp"

#include "globals.hpp"
#include "application.hpp"

int main(int, char**);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int)
{
    return main(__argc, __argv);
}


