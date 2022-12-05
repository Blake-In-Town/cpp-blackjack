#include <iostream>
#include <cassert>

#include "Deck.h"
#include "Card.h"

void Deck::printDeck() const {
    std::cout << " \n printDeck \n";
    for( const Card &card : m_deck ) {
        card.printCard();
    }
}

void Deck::shuffleDeck() {
    for (int index = 0; index < 52; ++index) {
        int swapIndex = getRandomNumber(0, 51);
        swapCard(m_deck[index], m_deck[swapIndex]);
    }
}

const Card& Deck::dealCard() {
    assert(m_cardIndex < 52);
    return m_deck[m_cardIndex++];
}

