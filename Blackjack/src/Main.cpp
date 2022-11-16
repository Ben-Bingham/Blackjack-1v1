#include <iostream>
#include <array>

#include "Card.h"
#include "CardList.h"

std::ostream& operator<<(std::ostream& os, const std::array<std::string, 9>& screen) {
    for (unsigned int i = 0; i < 9; i++) {
        os << screen[i] << std::endl;
    }
    return os;
}

// Dealers Hand: 
// CARD     CARD     CARD
// CARD     CARD     CARD
// CARD     CARD     CARD
// CARD     CARD     CARD
// CARD     CARD     CARD
// CARD     CARD     CARD
// CARD     CARD     CARD
// CARD     CARD     CARD
// CARD     CARD     CARD
//                              Spacing
// Your hand:
// CARD     CARD     CARD
// CARD     CARD     CARD
// CARD     CARD     CARD
// CARD     CARD     CARD
// CARD     CARD     CARD
// CARD     CARD     CARD
// CARD     CARD     CARD
// CARD     CARD     CARD
// CARD     CARD     CARD
//                              Spacing
int main() {
    Blackjack::CardList deck{ 1 };
    Blackjack::CardList dealersHand{ 0 };
    Blackjack::CardList playersHand{ 0 };

    std::array<std::string, 9> dealersHandScreen;
    std::array<std::string, 9> playersHandScreen;

    // Dealing              Courtesy of: https://bicyclecards.com/how-to-play/blackjack/
    playersHand.addCard(deck.draw()); // The dealer gives one card face up to each player in rotation clockwise.
    dealersHand.addCard(deck.draw()); // Then one card face up to themselves.
    playersHand.addCard(deck.draw()); // Another round of cards is then dealt face up to each player.
    dealersHand.addCard(deck.draw().flip()); // The dealer takes the second card face down.

    // Game Loop
    bool hit = true;
    // Get Input

    if (hit) {
        playersHand.addCard(deck.draw());
        if (playersHand.getTotal() > 21) {
            // Player busts
        }
    }
    else {

    }

    std::cin.get();
}