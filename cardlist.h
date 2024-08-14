#ifndef CARDLIST_H
#define CARDLIST_H

#include <vector>
#include "card.h"

class CardList {
private:
    std::vector<Card> cards;

public:
    void checkUniqueCardId(std::string& cardId);
    int checkCurrentYear();
    bool isLeapYear(int year);
    bool isValidDay(int day, int month, int year);
    bool isValidMonth(int month);
    bool isValidYear(int year, int currentYear);
    bool isValidDate(std::string& date);
    bool validateAccess(bool& access);
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
