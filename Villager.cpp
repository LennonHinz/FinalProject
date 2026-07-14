#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "npc.h"
#include "Villager.h"

using namespace std;


Villager::Villager(string n, string l, vector<string> t, vector<int> p) : npc(n, l) {
    trades = t;
    prices = p;
    friendship = 0;
}

void Villager::addTrade(string t) {
    trades.push_back(t);
}

void Villager::changeFriendship(int f) {
    if (friendship > f) {
        friendship += f;
    }else{
        friendship = 0;
    }
}

vector<string> Villager::getTrades() {
    return trades;
}

vector<int> Villager::getPrices() {
    return prices;
}

int Villager::getFriendship() {
    return friendship;
}