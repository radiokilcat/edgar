#include <iostream>
#include <filesystem>
#include "telegram_interface.hpp"
#include "settings.hpp"

int main(int argc, char** argv)
{
    settings settings(argc, argv);
    std::filesystem::path path(settings.vm_["file"].as<std::string>());

    telegram_interface interface(path);
    interface.main_loop();

    return 1;
}