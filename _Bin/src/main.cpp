#include <thread>
#include <string>
#include <iostream>
#include "gen8.h"

#include <vector>
#include <dpp/snowflake.h>
#include <unordered_map>

#include "Bot.h"

namespace Bot {
	std::unordered_map<uint64_t, std::vector<uint64_t>> Hosts;
}

int main() {
	botMain();
#if TRACK
	// Defult Set for debug
	Bot::Hosts[732965158795608094]
		.push_back(1253315446623571968);
#endif

	std::string UserInput;
	// this bot is online
	bool on = 1;

	while (on) {
		std::cin >> UserInput;
		switch (Gen8(UserInput.c_str())) {

		// kill code (kill/stop)
		case NumGen8<'k', 'i', 'l', 'l'>::val:
		case NumGen8<'s', 't', 'o', 'p'>::val: {
			on = 0;
		} break;
		default: break;
		}
	}

	std::cout << "loop out\n";
	return 0;
}