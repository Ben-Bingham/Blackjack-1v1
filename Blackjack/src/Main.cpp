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

int main() {
    Blackjack::CardList deck{ 1 };

    std::cout << deck << std::endl;
    deck.shuffle();
    std::cout << deck << std::endl;

    //Blackjack::Card card{ Blackjack::Card::Name::ACE, Blackjack::Card::Suite::SPADE };
    //std::cout << card << std::endl;

    std::cin.get();
}