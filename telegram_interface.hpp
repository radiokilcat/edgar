#pragma once

#include <tgbot/Bot.h>
#include "map"
#include "string"
#include "filesystem"


class telegram_interface {
public:
    int main_loop();
    telegram_interface(std::filesystem::path& p);

private:
    void read_config_file(std::filesystem::path& p);
    std::string token_;

    enum class tg_commands
    {
        start,
        saveTheWorld,
        feedTheCat
    };
};
