#ifndef VILLAGER_H
#define VILLAGER_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "npc.h"

using namespace std;

class Villager : public npc {
    private:
    vector<string> trades;
    int friendship;

    public:
    Villager(string n, string l, bool u, vector<string> t);
    void addTrade(string t);
    void changeFriendship(int f);
    vector<string> getTrades();
    int getFriendship();

};

#endif