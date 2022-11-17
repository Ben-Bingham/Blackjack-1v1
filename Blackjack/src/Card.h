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

		static std::pair<unsigned int, unsigned int> getValue(Name name);

		explicit Card(Name name = Name::ACE, Suite suite = Suite::SPADE, bool faceUp = true);

		[[nodiscard]] Name getName() const;
		[[nodiscard]] Suite getSuite() const;
		[[nodiscard]] std::string getAsciiVersion() const;
		[[nodiscard]] std::string getNameValue() const;
		[[nodiscard]] std::string getSymbolValue() const;

		Card& flip();
		Card& flipUp();

		void appendAsciiVersion(std::array<std::string, 9>& screen) const;

	private:
		Name m_Name;
		Suite m_Suite;
		std::string m_AsciiVersion;
		bool m_FaceUp;

		[[nodiscard]] std::string generateAsciiVersion() const;
	};

	std::ostream& operator<<(std::ostream& os, const Card& card);
}