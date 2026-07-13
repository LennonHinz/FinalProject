#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "Player.h"

using namespace std;


Player::Player(string n) {
    name = n;
    location = "Farm";
    gold = 100;
    averageSleep = 8;
    for (int i = 0; i < 10; i++) {
        inventory[i] = "";
    }
    sleepDeprived = false;
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
    cout << gold;
}

string Player::changeInventory(string item, int place) {
    string replace;
    replace = inventory[place];
    inventory[place] = item;
    return replace;
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

bool Player::getSleepDeprived() {
    return sleepDeprived;
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

void Player::tradeWithJoja() {
    int decition;
    cout << endl << endl << "Trading with joja..." << endl;
    cout << "1) Unlock entire map : 50 gold" << endl;
    cout << "2) Skip current bundle item : 50 gold" << endl;
    cout << "3) Stop trading with Joja" << endl;
    do {
        cout << "Enter you decition: ";
        cin >> decition;
    } while (decition <= 0 && decition > 3);

    switch (decition)
    {
    case 1:
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