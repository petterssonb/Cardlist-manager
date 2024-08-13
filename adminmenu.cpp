// AdminMenu.cpp
#include "adminmenu.h"
#include <iostream>

void AdminMenu::displayMenu(CardList& cardList) {
    int sel;
    while (true) {
        std::cout << "Admin Menu" << std::endl;
        std::cout << "1. Remote open door" << std::endl;
        std::cout << "2. List all cards in system" << std::endl;
        std::cout << "3. Add new card" << std::endl;
        std::cout << "4. Remove card from system" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "9. FAKE TEST SCAN CARD" << std::endl;

        std::cout << "Enter choice: ";
        std::cin >> sel;

        switch (sel) {
        case 1:
            std::cout << "CURRENTLY LAMP IS: Green" << std::endl;
            break;
        case 2:
            cardList.listAllCards();
            break;
        case 3:
            cardList.promptCardRegistration();
            break;
        case 4:
            cardList.promptCardRemoval();
        case 5:
            return;
        case 9:
            cardList.promptCardCheck();
            break;
        default:
            std::cout << "Invalid choice. Please select 1, 2, 3, 4, 5 or 9" << std::endl;
        }
    }
}
