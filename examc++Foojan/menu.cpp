//
// Created by WIN on 5/1/2022.
//


#include <list>
#include "menu.h"
#include "CarData.h"

Menu::Menu() {
    start();
}

int Menu::showMenu() {
    cout << "1)Add Car" << endl;
    cout << "2)Edit Car" << endl;
    cout << "3)Remove Car" << endl;
    cout << "4)Show All Cars" << endl;
    cout << "0)Exit" << endl;
    cout << "Enter Your Option : ";
    int option;
    cin >> option;
    return option;
}

void Menu::start() {
    list<Car> *carList;
    int option = showMenu();
    while (option != 0) {
        switch (option) {
            case 1:
                CarData CarData;
                carList.push_back(&CarData.getCar());
                break;
            case 2:
                cout << 2 << endl;
                break;
            case 3:
                cout << 3 << endl;
                break;
            case 4:
                for (int i = 0; i < carList.size(); i++){
                    cout << carList->getCar();
                }
                break;
            default:
                cout << "Invalid Option" << endl;
        }
        option = showMenu();
    }
}
