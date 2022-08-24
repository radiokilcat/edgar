#include "telegram_interface.hpp"
#include "tgbot/tgbot.h"

telegram_interface::telegram_interface(std::filesystem::path& p)
{
    read_config_file(p);
}

int telegram_interface::main_loop()
{
    const std::string photoFilePath = "example.jpg";
    const std::string photoMimeType = "image/jpeg";

    TgBot::Bot bot(token_);

    bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message)
    {
        bot.getApi().sendMessage(message->chat->id, "Hi!");
    });

//    bot.getEvents().onCommand("photo", [&bot, &photoFilePath, &photoMimeType](TgBot::Message::Ptr message) {
//            bot.getApi().sendPhoto(message->chat->id, TgBot::InputFile::fromFile(photoFilePath, photoMimeType));
//        });

    bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message)
    {
        if (!message->photo.empty())
        {
            bot.getApi().sendMessage(message->chat->id, "I received your photo, thx! ");
            return;
        }
        printf("User wrote %s\n", message->text.c_str());
        if (StringTools::startsWith(message->text, "/start"))
        {
            return;
        }
        bot.getApi().sendMessage(message->chat->id, "Your message is: " + message->text);
    });

    try {
        printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
        TgBot::TgLongPoll longPoll(bot);
        while (true) {
            printf("Long poll started\n");
            longPoll.start();
        }
    } catch (TgBot::TgException& e) {
        printf("error: %s\n", e.what());
    }
    return 0;
}

//std::string telegram_interface::string_command(tg_commands command)
//{
//    switch (command)
//    {
//      case tg_commands::start: return "start";
//      case tg_commands::feedTheCat: return "feedTheCat";
//      case tg_commands::saveTheWorld: return "saveTheWorld";
//    }
//}

void telegram_interface::read_config_file(std::filesystem::path& p)
{
    std::ifstream f;
    f.open(p);
    if (!f)
    {
        std::cerr << "file could not be opened" << std::endl;
        return;
    }
    while (f)
    {
        f >> token_;
    }
    std::cout << token_ << std::endl;
}
