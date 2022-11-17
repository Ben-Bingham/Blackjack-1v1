#include "CardList.h"
#include <random>
#include <iostream>

namespace Blackjack {
	CardList::CardList(unsigned int numberOfDecks)
		: m_NumberOfCards(numberOfDecks * 52) {

		for (unsigned int i = 0; i < numberOfDecks; i++) {
			for (const Card::Suite suite : m_Suites) {
				for (const Card::Name name : m_Names) {
					m_Cards.emplace_back(Card{ name, suite });
				}
			}
		}
	}

	void CardList::shuffle() {
		std::vector<Card> shuffledCards;

		while (shuffledCards.size() < m_NumberOfCards) {
			std::random_device dev;
			std::mt19937 rng(dev());
			std::uniform_int_distribution<std::mt19937::result_type> randomValue(0, static_cast<int>(m_Cards.size()) - 1);

			const unsigned int randomIndex = randomValue(rng);

			shuffledCards.push_back(*(m_Cards.begin() + randomIndex));

			m_Cards.erase(m_Cards.begin() + randomIndex);
		}

		m_Cards = shuffledCards;
	}

	Card CardList::draw() {
		Card card = m_Cards[m_NumberOfCards - 1];
		m_Cards.pop_back();
		m_NumberOfCards--;
		return card;
	}

	void CardList::flipAllUp() {
		for (Card& card : m_Cards) {
			card.flipUp();
		}
	}

	void CardList::addCard(const Card& card) {
		m_Cards.push_back(card);
	}

	unsigned int CardList::getNumberOfCards() const {
		return m_NumberOfCards;
	}

	std::vector<Card> CardList::getCards() const {
		return m_Cards;
	}

	std::array<std::string, 9> CardList::getVisuals() const {
		std::array<std::string, 9> visuals;
		for (const Card& card : m_Cards) {
			card.appendAsciiVersion(visuals);
		}

		return visuals;
	}

	std::pair<unsigned int, unsigned int> CardList::getTotal() const {
		std::pair<unsigned int, unsigned int> results;
		for (const Card& card : m_Cards) {
			results.first += Card::getValue(card.getName()).first;
			results.second += Card::getValue(card.getName()).second;
		}
		return results;
	}

	const std::array<Card::Suite, 4> CardList::m_Suites = {
		Card::Suite::SPADE,
		Card::Suite::CLUB,
		Card::Suite::HEART,
		Card::Suite::DIAMOND
	};

	const std::array<Card::Name, 13> CardList::m_Names = {
		Card::Name::ACE,
		Card::Name::TWO,
		Card::Name::THREE,
		Card::Name::FOUR,
		Card::Name::FIVE,
		Card::Name::SIX,
		Card::Name::SEVEN,
		Card::Name::EIGHT,
		Card::Name::NINE,
		Card::Name::TEN,
		Card::Name::JACK,
		Card::Name::QUEEN,
		Card::Name::KING
	};

	std::ostream& operator<<(std::ostream& os, const CardList& cardList) {
		const std::vector<Card> cards = cardList.getCards();

		for (unsigned int i = 0; i < 52; i++) {
			os << cards[i] << '\n';
		}

		return os;
	}
}