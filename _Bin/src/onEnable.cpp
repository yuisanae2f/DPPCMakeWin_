#include <dpp/once.h>
#include <dpp/appcommand.h>

#include "Bot.h"

namespace Bot {
	void onEnable(const dpp::ready_t& ev) {
		/* Wrap command registration in run_once to make sure it doesnt run on every full reconnection */
		if (dpp::run_once<struct register_bot_commands>()) {
			std::vector<dpp::slashcommand> commands {
				dpp::slashcommand("ping", "Ping pong! Pong!", bot.me.id),
			}; 

			bot.global_bulk_command_create(commands);
		}
	}
}