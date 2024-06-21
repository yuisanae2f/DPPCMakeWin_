#pragma once
#include <dpp/cluster.h>
/* Create bot cluster */
extern dpp::cluster bot;

namespace Bot {
	/// <summary>
	/// Bot event on invoked (when on first run);
	/// Data will be initialised here (mainly here, slash commands...)
	/// </summary>
	/// <param name="ev">Event invoke</param>
	extern void onEnable(const dpp::ready_t& ev);

	/// <summary>
	/// Handle the event (received slash command)
	/// </summary>
	/// <param name="ev">The slash command</param>
	/// <returns>[TASK], used on coroutine</returns>
	extern dpp::task<void> slashCommand(const dpp::slashcommand_t& ev);

	/// <summary>
	/// Function defined to handle the event (button)
	/// </summary>
	/// <param name="ev">Button click event</param>
	/// <returns></returns>
	extern dpp::task<void> onButtonClick(const dpp::button_click_t& ev);
	/// <summary>
	/// on form has submit(A.K.A. MODAL)
	/// </summary>
	/// <param name="ev">event did catch</param>
	/// <returns>TASK, used on coroutine</returns>
	extern dpp::task<void> onFormSubmit(const dpp::form_submit_t& ev);

	/* Guild(Server) - Contributor(Channels) */
	extern std::unordered_map<uint64_t, std::vector<uint64_t>> Hosts;
}

#pragma region ID pre-built in order to boost them
namespace Inquiry {
	constexpr const char
		* Question = "\x1\x40",
		* Answer = "\x1\x40\x2";
}

namespace Slash {
	namespace InquiryCaution {
		constexpr const char
			* yes = "\x1",
			* no = "\x1\x1";
	}

	namespace Answer {
		constexpr const char
			* prefix = "\x2\x40";
	}
}
#pragma endregion

/// <summary>
/// Bot start logic here...
/// </summary>
extern void botMain();