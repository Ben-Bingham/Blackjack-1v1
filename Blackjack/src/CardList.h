#pragma once

#include <vector>
#include <cstdlib>
#include <array>

#include "Card.h"

namespace Blackjack {
	class CardList {
	public:
		CardList(unsigned int numberOfDecks);

		void shuffle();
		Card draw();

		unsigned int getNumberOfCards() const;

		std::vector<Card> getCards() const;

		void addCard(Card card);

	private:
		std::vector<Card> m_Cards;
		unsigned int m_NumberOfCards;

		static const std::array<Card::Suite, 4> m_Suites;
		static const std::array<Card::Name, 13> m_Names;
	};

	std::ostream& operator<<(std::ostream& os, const CardList& cardList);
}