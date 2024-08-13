#ifndef CARDLIST_H
#define CARDLIST_H

#include <vector>
#include "card.h"

class CardList {
private:
    std::vector<Card> cards;

public:
    void promptCardRegistration();
    void addCard(const Card& card);
    void promptCardRemoval();
    void removeCard(const std::string& cardId);
    void promptCardCheck();
    bool checkCard(const std::string& cardId) const;
    void listAllCards() const;
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename) const;
};

#endif // CARDLIST_H
