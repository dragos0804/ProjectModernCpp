#pragma once
#include "Register.h"
#include "Storage.h"
#include <conio.h>
#include <Windows.h>
#include "Login.h"

class UserInterface
{
public:
    void StartUpMenu(Register r, AppStorage storage);

private:
    void RegisterMenu(Register r, AppStorage storage);

    void LoginMenu(Register r, AppStorage storage);
};

