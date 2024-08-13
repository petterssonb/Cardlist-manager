#include "cardlist.h"
#include <iostream>
#include <fstream>

void CardList::promptCardRegistration(){
    std::string cardId, regDate;
    bool access;
    std::cout << "Enter card ID: ";
    std::cin >> cardId;
    std::cout << "Enter registration date (YYYY-MM-DD): ";
    std::cin >> regDate;
    std::cout << "Enter access (1 for access, 0 for no access): ";
    std::cin >> access;
    addCard(Card(cardId, access, regDate));
}

void CardList::addCard(const Card& card) {
    cards.push_back(card);
}

void CardList::promptCardRemoval() {
    std::string cardId;
    std::cout << "Enter card ID to remove: ";
    std::cin >> cardId;
    removeCard(cardId);
}

void CardList::removeCard(const std::string& cardId) {
    auto it = std::remove_if(cards.begin(), cards.end(),
                             [cardId](const Card& card) {
                                 return card.getCardId() == cardId; 
                             });

    if(it != cards.end()){
        cards.erase(it, cards.end());
        std::cout << "Card removed successfully." << std::endl;
    } else{
        std::cout << "Card ID not found in the system." << std::endl;
    }
}

void CardList::promptCardCheck() {
    std::string cardId;
    std::cout << "Enter card ID to check: ";
    std::cin >> cardId;
    if (checkCard(cardId)) {
        std::cout << "Card ID " << cardId << " is in the system." << std::endl;
    } else {
        std::cout << "Card ID " << cardId << " is not in the system." << std::endl;
    }
}

bool CardList::checkCard(const std::string& cardId) const {
    for (const auto& card : cards) {
        if (card.getCardId() == cardId) {
            return true;
        }
    }
    return false;
}

void CardList::listAllCards() const {
    for (const auto& card : cards) {
        std::cout << card.getCardId() << " "
                  << (card.hasAccess() ? "Access" : "No Access") << " "
                  << card.getRegDate() << std::endl;
    }
}

void CardList::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "There was no data found." << std::endl;
        return;
    }

    std::string cardId, regDate;
    bool access;
    while (file >> cardId >> access >> regDate) {
        cards.emplace_back(cardId, access, regDate);
    }
}

void CardList::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    for (const auto& card : cards) {
        file << card.getCardId() << " " << card.hasAccess() << " " << card.getRegDate() << std::endl;
    }
}
