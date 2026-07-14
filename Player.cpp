#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "Player.h"
#include "Villager.h"

using namespace std;


Player::Player(string n) {
    name = n;
    location = "Farm";
    gold = 100;
    averageSleep = 8;
    jojaInfluence = 0;
}

void Player::setLocation(string l) {
    location = l;
}

void Player::setAverageSleep(double lN, int day) {
    averageSleep = ((averageSleep * (day - 1)) + (lN + 6)) / day;
    cout << averageSleep;
}

void Player::changeGold(int g) {
    gold += g;
}

string Player::getName() {
    return name;
}

string Player::getLocation() {
    return location;
}

double Player::getAverageSleep() {
    return averageSleep;
}

int Player::getGold() {
    return gold;
}

void Player::UnlockMines() {
    minesUnlock = true;
}

bool Player::getMinesUnlock() {
    return minesUnlock;
}

void Player::UnlockDocks() {
    docksUnlock = true;
    minesUnlock = true;
}

bool Player::getDocksUnlock() {
    return docksUnlock;
}

void Player::printInventory() {
    if (0 != static_cast<int>(inventory.size())){
        cout << "Current Inventory:" << endl;
        for (int i = 0; i < static_cast<int>(inventory.size()); i++) {
            cout << inventory[i] << endl;
        }
        cout << endl;
    }  
}

void Player::tradeWithJoja() {
    int decision;
    cout << endl << endl << "Trading with joja..." << endl;
    cout << "1) Unlock entire map : 50 gold : +1 Joja Influence" << endl;
    cout << "2) Skip current bundle item : 50 gold : +1 Joja Influence" << endl;
    cout << "3) Stop trading with Joja" << endl;
    do {
        cout << "Enter you decition: ";
        cin >> decision;
    } while (decision <= 0 || decision > 3);

    switch (decision)
    {
    case 1:
    if (gold < 50) {
        cout << "Not enough gold" << endl;
        return;
    }
    UnlockDocks();
    gold -= 50;
    jojaInfluence++;
    break;
    case 2:
    // add once bundle is added
    break;
    default:
    break;
    }
}

void Player::villagerTrading(vector<Villager> villagers, int vIndex) {
    vector<string> trades = villagers[vIndex].getTrades();
    vector<int> prices = villagers[vIndex].getPrices();
    int decision;

    cout << endl << endl << "Trading with " << villagers[vIndex].getName() << "..." << endl;

    for (int i = 0; i < static_cast<int>(trades.size()); i++) {
        cout << (i + 1) << ") " << trades[i] << " : " << prices[i] << endl;
    }

    cout << (trades.size() + 1) << ") Stop trading" << endl;

    do {
        cout << "Enter you decition: ";
        cin >> decision;
    } while (decision <= 0 || decision > (static_cast<int>(trades.size()) + 1));

    if (decision == (static_cast<int>(trades.size()) + 1)) {
        return;
    }

    if (gold < prices[(decision - 1)]) {
        cout << "Not enough gold" << endl;
        return;
    }

    inventory.push_back(trades[(decision - 1)]);
    changeGold(-prices[(decision - 1)]);

}

vector<string> Player::donateItem(vector<string> bundle) {
    int decision;

    cout << endl << endl << "Donating items..." << endl;

    for (int i = 0; i < static_cast<int>(bundle.size()); i++) {
        cout << (i + 1) << ") " << bundle[i] << endl;
    }

    cout << (bundle.size() + 1) << ") Stop donating" << endl;

    do {
        cout << "Enter you decition: ";
        cin >> decision;
    } while (decision <= 0 || decision > (static_cast<int>(bundle.size()) + 1));

    if (decision == (static_cast<int>(bundle.size()) + 1)) {
        return bundle;
    }

    for (int i = 0; i < static_cast<int>(inventory.size()); i++) {
        if (bundle[decision - 1] == inventory[i]) {
            inventory.erase(inventory.begin() + i);
            bundle.erase(bundle.begin() + decision - 1);
            return bundle;
        }
    }

    cout << "Could not find item in inventory" << endl;
    return bundle;
}