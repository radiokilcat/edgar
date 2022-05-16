#include <iostream>
#include "telegram_interface.hpp"
#include "settings.hpp"

int main(int argc, char** argv)
{
    settings settings(argc, argv);
    return telegram_interface::main_loop();
}