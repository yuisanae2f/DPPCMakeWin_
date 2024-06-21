#include <dpp/once.h>
#include <dpp/appcommand.h>

#include "Bot.h"
#include "gen8.h"

namespace Bot {
	dpp::task<void> slashCommand(const dpp::slashcommand_t& ev) {
		switch (Gen8(ev.command.get_command_name().c_str())) {
		case NumGen8<'p', 'i', 'n', 'g'>::val: {
			co_await ev.co_reply("Pong!");
		} break;
		}

		co_return;
	}
}