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
}

void Player::setLocation(string l) {
    location = l;
}

void Player::setAverageSleep(double lN, int day) {
    averageSleep = ((averageSleep * (day - 1)) + lN) / day;
}

void Player::changeGold(int g) {
    gold += g;
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