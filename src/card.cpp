#include "card.h"

Card::Card(const std::string& id, bool accessStatus, const std::string& date)
    : cardId(id), access(accessStatus), regDate(date) {}

std::string Card::getCardId() const {
    return cardId;
}

bool Card::hasAccess() const {
    return access;
}

std::string Card::getRegDate() const {
    return regDate;
}

void Card::setAccess(bool accessStatus) {
    access = accessStatus;
}
