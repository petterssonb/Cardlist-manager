#include "cardlist.h"
#include "adminmenu.h"

int main() {
    CardList cardList;
    cardList.loadFromFile("cardList_data.txt");

    AdminMenu adminMenu;
    adminMenu.displayMenu(cardList);

    cardList.saveToFile("cardList_data.txt");

    return 0;
}
