// AdminMenu.h
#ifndef ADMINMENU_H
#define ADMINMENU_H

#include "cardlist.h"

class AdminMenu {
public:
    void refreshMenu();
    void displayMenu(CardList& cardList);
};

#endif // ADMINMENU_H
