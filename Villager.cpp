#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "npc.h"
#include "Villager.h"

using namespace std;


Villager::Villager(string n, string l, bool u, vector<string> t) : npc(n, l, u) {
    trades = t;
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

int Villager::getFriendship() {
    return friendship;
}