#include "Card.h"

#include <array>
#include <iostream>

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
			return "/>";
		default:
			return "An error occured";
		}
	}

	std::string Card::generateAsciiVersion() {
		std::string V = getNameValue(); // Number on card
		std::string S = getSymbolValue(); // Suite Symbol

		std::string I = std::string{ (char)179 }; // Vertical bar
		std::string t = std::string{ (char)196 }; // Horizontal bar

		std::string O = std::string{ " " }; // Background
		
		std::string w = std::string{ (char)218 }; // Top left Corner
		std::string a = std::string{ (char)191 }; // Top right Corner
		std::string s = std::string{ (char)192 }; // Bottom left Corner
		std::string d = std::string{ (char)217 }; // Bottom right Corner

		std::string card =
			"" + w + t + t + t + t + t + t + t + t + t + a + "\n"
			"" + I + V + O + O + O + O + O + O + O + I + "\n"
			"" + I + O + O + O + O + O + O + O + O + O + I + "\n"
			"" + I + O + O + O + O + O + O + O + O + O + I + "\n"
			"" + I + O + O + O + S + O + O + O + O + I + "\n"
			"" + I + O + O + O + O + O + O + O + O + O + I + "\n"
			"" + I + O + O + O + O + O + O + O + O + O + I + "\n"
			"" + I + O + O + O + O + O + O + O + V + I + "\n"
			"" + s + t + t + t + t + t + t + t + t + t + d;

		return card;
	}

	void Card::appendAsciiVersion(std::array<std::string, 9>& screen) {
		std::string V = getNameValue(); // Number on card
		std::string S = getSymbolValue(); // Suite Symbol

		std::string I = std::string{ (char)179 }; // Vertical bar
		std::string t = std::string{ (char)196 }; // Horizontal bar

		std::string O = std::string{ " " }; // Background

		std::string w = std::string{ (char)218 }; // Top left Corner
		std::string a = std::string{ (char)191 }; // Top right Corner
		std::string s = std::string{ (char)192 }; // Bottom left Corner
		std::string d = std::string{ (char)217 }; // Bottom right Corner

		screen[0].append("" + w + t + t + t + t + t + t + t + t + t + a);
		screen[1].append("" + I + V + O + O + O + O + O + O + O + I);
		screen[2].append("" + I + O + O + O + O + O + O + O + O + O + I);
		screen[3].append("" + I + O + O + O + O + O + O + O + O + O + I);
		screen[4].append("" + I + O + O + O + S + O + O + O + O + I);
		screen[5].append("" + I + O + O + O + O + O + O + O + O + O + I);
		screen[6].append("" + I + O + O + O + O + O + O + O + O + O + I);
		screen[7].append("" + I + O + O + O + O + O + O + O + V + I);
		screen[8].append("" + s + t + t + t + t + t + t + t + t + t + d);
	}


	std::ostream& operator<<(std::ostream& os, const Card& card) {
		os << card.getAsciiVersion();
		return os;
	}
}