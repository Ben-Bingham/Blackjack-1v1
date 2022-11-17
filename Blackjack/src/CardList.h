#pragma once

#include <vector>
#include <array>

#include "Card.h"

namespace Blackjack {
	class CardList {
	public:
		CardList(unsigned int numberOfDecks);

		void shuffle();
		Card draw();
		void flipAllUp();

		[[nodiscard]] unsigned int getNumberOfCards() const;

		[[nodiscard]] std::vector<Card> getCards() const;
		[[nodiscard]] std::array<std::string, 9> getVisuals() const;
		[[nodiscard]] std::pair<unsigned int, unsigned int> getTotal() const;

		void addCard(const Card& card);

	private:
		std::vector<Card> m_Cards;
		unsigned int m_NumberOfCards;

		static const std::array<Card::Suite, 4> m_Suites;
		static const std::array<Card::Name, 13> m_Names;
	};

	std::ostream& operator<<(std::ostream& os, const CardList& cardList);
}