//
// Created by alex on 3/20/22.
//

#ifndef EDGAR_TELEGRAM_INTERFACE_HPP
#define EDGAR_TELEGRAM_INTERFACE_HPP

#include <tgbot/Bot.h>
#include "map"
#include "string"


class telegram_interface {
public:
    static int main_loop();
    telegram_interface();

private:
//    std::map<tg_commands, std::function<>> router_;
  TgBot::Bot bot_;

  enum class tg_commands
  {
    start,
    saveTheWorld,
    feedTheCat
  };

  void handleCommand();
  std::string string_command(tg_commands command);

  std::array<std::string, 3> commands_ = {
      "start",
      "saveTheWorld",
      "feedTheCat"
  };

};


#endif //EDGAR_TELEGRAM_INTERFACE_HPP
