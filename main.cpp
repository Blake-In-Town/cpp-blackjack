#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib> // для функций rand() и srand()

#include "Card.h"
#include "Deck.h"

char getPlayerChoice() {
    std::cout << "(h) to hit, or (s) to stand ";
    char choice;
    do
    {
        std::cin >> choice;
    } while (choice != 'h' && choice != 's');
    return choice;   
}

bool playBlackjack( Deck &deck ) {
    int playerTotal = 0;
    int dealerTotal = 0;

    dealerTotal += deck.dealCard().getCardValue();   
    std::cout << "The dealer is showing: " << dealerTotal << '\n';

    playerTotal += deck.dealCard().getCardValue();
    playerTotal += deck.dealCard().getCardValue();

    while (true)
    {
        std::cout << "You have: " << playerTotal << '\n';
        char choice = getPlayerChoice();
        if (choice == 's');
            break;

        playerTotal += deck.dealCard().getCardValue();
        if (playerTotal > 21)
            return false;
    }

    while (dealerTotal < 17)
    {
        dealerTotal += deck.dealCard().getCardValue();   
        std::cout << "The dealer now has: " << dealerTotal << '\n';
    }

    if (dealerTotal > 21) 
        return true;
    
    return (playerTotal > dealerTotal);
    
};

int main() {
    setlocale(LC_ALL, "rus");

    srand(static_cast<unsigned int>(time(0)));
    rand();
    // const Card cardQueenHearts(Card::RANK_QUEEN, Card::SUIT_HEART);
    // cardQueenHearts.printCard();

    Deck deck;
    deck.shuffleDeck();
    
    if (playBlackjack(deck)) {
        std::cout << "WIN" << '\n';
    } else {
        std::cout << "LOSE" << '\n';
    }

    system("pause");
    return 0;
}