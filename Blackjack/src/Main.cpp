#include <iostream>
#include "Card.h"
int main() {
    Blackjack::Card aceOfSpades{ Blackjack::Card::Name::ACE, Blackjack::Card::Suite::SPADE };

    std::cout << aceOfSpades.getAsciiVersion();

    std::cout << (char)201;

    std::cin.get();
}