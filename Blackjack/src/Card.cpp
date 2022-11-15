#include "Card.h"

namespace Blackjack {
	Card::Card(Name name, Suite suite)
		: m_Name(name), m_Suite(suite), m_AsciiVersion(generateAsciiVersion()) {
	}

	Card::Name Card::getName() const {
		return m_Name;
	}

	Card::Suite Card::getSuite() const {
		return m_Suite;
	}

	std::string Card::getAsciiVersion() const {
		return m_AsciiVersion;
	}

	std::string Card::getNameValue() const {
		switch (m_Name) {
		case Blackjack::Card::Name::ACE:
			return "A ";
		case Blackjack::Card::Name::TWO:
			return "2 ";
		case Blackjack::Card::Name::THREE:
			return "3 ";
		case Blackjack::Card::Name::FOUR:
			return "4 ";
		case Blackjack::Card::Name::FIVE:
			return "5 ";
		case Blackjack::Card::Name::SIX:
			return "6 ";
		case Blackjack::Card::Name::SEVEN:
			return "7 ";
		case Blackjack::Card::Name::EIGHT:
			return "8 ";
		case Blackjack::Card::Name::NINE:
			return "9 ";
		case Blackjack::Card::Name::TEN:
			return "10";
		case Blackjack::Card::Name::JACK:
			return "J ";
		case Blackjack::Card::Name::QUEEN:
			return "Q ";
		case Blackjack::Card::Name::KING:
			return "K ";
		default:
			return "An error occured.";
		}
	}

	std::string Card::getSymbolValue() const {
		switch (m_Suite) {
		case Blackjack::Card::Suite::CLUB:
			return "%&";
		case Blackjack::Card::Suite::DIAMOND:
			return "<>";
		case Blackjack::Card::Suite::HEART:
			return "<3";
		case Blackjack::Card::Suite::SPADE:
			return ")>";
		default:
			return "An error occured";
		}
	}

	std::string Card::generateAsciiVersion() {
		std::string value = getNameValue();
		std::string symbol = getSymbolValue();


		std::string card = 
		"+---------+\n"
		"|" + value + "       |\n"
		"|         |\n"
		"|         |\n"
		"|   " + symbol +"    |\n"
		"|         |\n"
		"|         |\n"
		"|       " + value +"|\n"
		"+---------+";
		return card;
	}
}