#include <algorithm>
#include <iostream>
#include <array>

#include "Card.h"
#include "CardList.h"

using CardVisuals = std::array<std::string, 9>;
std::ostream& operator<<(std::ostream& os, const std::array<std::string, 9>& visuals) {
    for (unsigned int i = 0; i < 9; i++) {
        os << visuals[i] << std::endl;
    }
    return os;
}

bool bust(const Blackjack::CardList& cardList) {
    std::pair<unsigned int, unsigned int> totals = cardList.getTotal();
	if (totals.first <= 21 || totals.second <= 21) {
        return false;
	}
    return true;
}

bool getPlayerInput(const std::string& question, const std::vector<std::string>& acceptedAnswers) {
    std::cout << question << std::endl;
    std::string input;
    std::cin >> input;

    if (std::any_of(acceptedAnswers.begin(), acceptedAnswers.end(),[input](const std::string& answer) {return input == answer;})) {
        return true;
    }

    return false;
}

void clearConsole() {
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

bool playAgain() {
    return getPlayerInput("Would you like to play again? (Y/n)", { "Yes", "yes", "Y", "y" });
}

void playerLose() {
    std::cout << "You lose." << std::endl;
}

void playerWin() {
    std::cout << "You win!" << std::endl;
}

void printBoard(const Blackjack::CardList& dealersHand, const Blackjack::CardList& playersHand) {
    const CardVisuals dealersVisuals = dealersHand.getVisuals();
    const CardVisuals playerVisuals = playersHand.getVisuals();

    clearConsole();

    std::cout << "Dealers Hand:\n";
    std::cout << dealersVisuals << '\n';
    std::cout << '\n';
    std::cout << "Players Hand:\n";
    std::cout << playerVisuals << '\n';
    std::cout << "=====================================================================" << std::endl;
}

int main() { // Rules courtesy of: https://bicyclecards.com/how-to-play/blackjack/
    do {
        clearConsole();

        Blackjack::CardList deck{ 1 };
        Blackjack::CardList dealersHand{ 0 };
        Blackjack::CardList playersHand{ 0 };

        bool playerLost = false;

        printBoard(dealersHand, playersHand);

        deck.shuffle();

        // Dealing
        playersHand.addCard(deck.draw()); // The dealer gives one card face up to each player in rotation clockwise.
        dealersHand.addCard(deck.draw()); // Then one card face up to themselves.
        playersHand.addCard(deck.draw()); // Another round of cards is then dealt face up to each player.
        dealersHand.addCard(deck.draw().flip()); // The dealer takes the second card face down.

        printBoard(dealersHand, playersHand);

        // Game Loop
        while (getPlayerInput("Do you want another card? (Y/n)", { "Yes", "yes", "y", "Y", "Hit", "hit" })) {
            playersHand.addCard(deck.draw());
            printBoard(dealersHand, playersHand);

            if (bust(playersHand)) {
                playerLose();
                playerLost = true;
                break;
            }

            playerLost = false;
        }

        if (!playerLost) {
            // Dealer must now play
            dealersHand.flipAllUp();
            printBoard(dealersHand, playersHand);

            std::pair<unsigned int, unsigned int> totals = dealersHand.getTotal();
            while (totals.first < 17 && totals.second < 17) { // If the total is 16 or under, they must take a card.
                dealersHand.addCard(deck.draw()); // Dealer hits
                printBoard(dealersHand, playersHand);
                totals = dealersHand.getTotal();
            }
            // If the total is 17 or more, it must stand.
            // If the dealer has an ace, and counting it as 11 would bring the total to 17 or more (but not over 21), the dealer must count the ace as 11 and stand.

            const std::pair<unsigned int, unsigned int> playersTotals = playersHand.getTotal();
            const std::pair<unsigned int, unsigned int> dealersTotals = dealersHand.getTotal();

            if (playersTotals.first >= dealersTotals.first || playersTotals.second >= dealersTotals.first || playersTotals.first >= dealersTotals.second || playersTotals.second >= dealersTotals.second) {
                playerLost = false;
                playerWin();
            }
            else {
                playerLose();
            }
        }

    } while (playAgain());
}