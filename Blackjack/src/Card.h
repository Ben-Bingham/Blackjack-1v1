#pragma once

#include <string>

namespace Blackjack {
	class Card {
	public:
		enum class Suite {
			SPADE,
			CLUB,
			HEART,
			DIAMOND
		};

		enum class Name {
			ACE,
			TWO,
			THREE,
			FOUR,
			FIVE,
			SIX,
			SEVEN,
			EIGHT,
			NINE,
			TEN,
			JACK,
			QUEEN,
			KING
		};

		Card(Name name = Name::ACE, Suite suite = Suite::SPADE);

		Name getName() const;
		Suite getSuite() const;
		std::string getAsciiVersion() const;
		std::string getNameValue() const;
		std::string getSymbolValue() const;
		void appendAsciiVersion(std::array<std::string, 9>& screen);

	private:
		Name m_Name;
		Suite m_Suite;
		std::string m_AsciiVersion;

		std::string generateAsciiVersion();
	};

	std::ostream& operator<<(std::ostream& os, const Card& card);
}