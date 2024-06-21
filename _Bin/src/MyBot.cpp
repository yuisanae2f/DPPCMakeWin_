#include "MyBot.h"

#include <type_traits>
#include <dpp/dpp.h>
#include "gen8.h"

#include "Bot.h"

#pragma region TOKEN
#ifndef BOT_TOKEN
#error You need to define [BOT_TOKEN]. you can build a token in __dppCMakeWin/_Bin/src/MyBot.cpp
#endif // !BOT_TOKEN


dpp::cluster bot(BOT_TOKEN);
#pragma endregion

void botMain()
{
	/* Output simple log messages to stdout */
	bot.on_log(dpp::utility::cout_logger());
	bot.on_ready(Bot::onEnable);
	bot.on_slashcommand(Bot::slashCommand);

	/* Start the bot */
	bot.start(dpp::start_type::st_return);

	return;
}