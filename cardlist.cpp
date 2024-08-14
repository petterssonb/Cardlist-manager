#include "cardlist.h"
#include <iostream>
#include <fstream>
#include <regex>
#include <ctime>
#include <limits>

#define LEAP_YEAR 4
#define CENTURY 100
#define FOUR_CENTURIES 400

enum Months{
    JANUARY = 1,
    FEBRUARY = 2,
    MARCH = 3,
    APRIL = 4,
    MAY = 5,
    JUNE = 6,
    JULY = 7,
    AUGUST = 8,
    SEPTEMBER = 9,
    OCTOBER = 10,
    NOVEMBER = 11,
    DECEMBER = 12
};

void CardList::checkUniqueCardId(std::string& cardId) {
    while(true){
        std::cout << "Enter card ID: ";
        std::cin >> cardId;
        if(checkCard(cardId)){
            std::cout << "Card ID already exists in the system." << std::endl;
        } else{
            break;
        }
    }
}

int CardList::checkCurrentYear(){
    time_t t = time(0);
    tm* now = localtime(&t);
    return now->tm_year + 1900;
}

bool CardList::isLeapYear(int year){
    return (year % LEAP_YEAR == 0 && year % CENTURY != 0) || (year % FOUR_CENTURIES == 0);
}

bool CardList::isValidDay(int day, int month, int year){
    if(day < 1 || day > 31) return false;

    if(month == FEBRUARY){
        return day <= (isLeapYear(year) ? 29 : 28);
    } else if(month == APRIL || month == JUNE || month == SEPTEMBER || month == NOVEMBER){
        return day <= 30;
    }
    return true;
}

bool CardList::isValidMonth(int month){
    return month >= JANUARY && month <= DECEMBER;
}

bool CardList::isValidYear(int year, int currentYear){
    return year >= currentYear;
}

bool CardList::isValidDate(std::string& date){
    std::regex dateRegex(R"((\d{4})-(\d{2})-(\d{2}))");
    std::smatch match;

    if(std::regex_match(date, match, dateRegex)){
        int year = std::stoi(match[1]);
        int month = std::stoi(match[2]);
        int day = std::stoi(match[3]);

        int currentYear = checkCurrentYear();

        if(!isValidYear(year, currentYear)) return false;
        if(!isValidMonth(month)) return false;
        if(!isValidDay(day, month, year)) return false;
        return true;
    }
    return false;
}

bool CardList::validateAccess(bool& access){
    while(true){
        std::cout << "Enter access (1 for access, 0 for no access): ";
        std::cin >> access;

        if(std::cin.fail() || (access != 1 && access != 0)){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter 1 or 0." << std::endl;
        }else {
            return true;
        }
    }
}

void CardList::promptCardRegistration(){
    std::string cardId, regDate;
    bool access;
    checkUniqueCardId(cardId);
    while(true){
        std::cout << "Enter registration date (YYYY-MM-DD): ";
        std::cin >> regDate;
        if(isValidDate(regDate)){
            break;
        } else{
            std::cout << "Invalid date format. Please enter a valid date." << std::endl;
        }
    }
    validateAccess(access);
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
    const std::string greenText = "\033[32m";
    const std::string redText = "\033[31m";
    const std::string resetText = "\033[0m";

    for (const auto& card : cards) {
        std::string accessStatus = card.hasAccess() ? "Access" : "No Access";
        std::string color = card.hasAccess() ? greenText : redText;


        std::cout << card.getCardId() << " "
                  << color << accessStatus << resetText << " "
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
