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
    averageSleep[0] = 8;
    for (int i = 0; i < 10; i++) {
        inventory[i] = "";
    }
    sleepDeprived = false;
}

void Player::setLocation(string l) {
    location = l;
}

void Player::setAverageSleep(double lN, int day) {
    averageSleep[0] = ((averageSleep[0] * (day - 1)) + (lN + 6)) / day;
    cout << averageSleep[0];
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
    return averageSleep[0];
}

int Player::getGold() {
    return gold;
}

bool Player::getSleepDeprived() {
    return sleepDeprived;
}