#ifndef DECK_H
#define DECK_H

#include <array>
#include <cstdlib> // для функций rand() и srand()

#include "Card.h"

    class Deck
    {
    private:
        std::array<Card, 52> m_deck;
        int m_cardIndex = 0;
        static int getRandomNumber(int min, int max) {
            static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
            return static_cast<int>(rand() * fraction * (max - min + 1) + min);
        };

        static void swapCard(Card &a, Card &b) {
            Card temp = a;
            a = b;
            b = temp;
        };

    public:
        Deck() {
            int card = 0;
            for (int suit = 0; suit < Card::MAX_SUITS; ++suit)
                for(int rank = 0; rank < Card::MAX_RANKS; ++rank) {
                    m_deck[card] = Card(static_cast<Card::CardRank>(rank), static_cast<Card::CardSuit>(suit));
                    ++card;
                }
        };

        void printDeck() const ;

        void shuffleDeck();

        const Card& dealCard();        
    };
    
    
#endif

