//
// Created by alex on 3/20/22.
//

#include "telegram_interface.hpp"
#include "tgbot/tgbot.h"

telegram_interface::telegram_interface()
  : bot_("aldksfjaldksfj")
{

}

int telegram_interface::main_loop() {

  /* TODO: read config */

    TgBot::Bot bot("1355180721:AAHgC-zybPnOmv41VgeYuLFc1wwKwkPwNxg");



    bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Hi!");
    });

    bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
        printf("User wrote %s\n", message->text.c_str());
        if (StringTools::startsWith(message->text, "/start")) {
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

std::string telegram_interface::string_command(tg_commands command)
{
    switch (command) {
      case tg_commands::start: return "start";
      case tg_commands::feedTheCat: return "feedTheCat";
      case tg_commands::saveTheWorld: return "saveTheWorld";
    }
}
