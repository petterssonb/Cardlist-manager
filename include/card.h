#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
private:
    std::string cardId;
    bool access;
    std::string regDate;

public:
    Card(const std::string& id, bool accessStatus, const std::string& date);
    std::string getCardId() const;
    bool hasAccess() const;
    std::string getRegDate() const;
    void setAccess(bool accessStatus);
};

#endif // CARD_H
