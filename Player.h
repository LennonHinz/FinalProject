#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "Villager.h"

using namespace std;

class Player { // the charactor the player is in control of
    private:
    string name;
    string location;
    double averageSleep;
    int gold;
    int jojaInfluence;
    bool minesUnlock = false;
    bool docksUnlock = false;
    vector<string> inventory;

    public:
    Player(string n);
    void setLocation(string l);
    void setAverageSleep(double lN, int day);
    void changeGold(int g);
    string getName();
    string getLocation();
    double getAverageSleep();
    int getGold();
    void UnlockMines();
    bool getMinesUnlock();
    void UnlockDocks();
    bool getDocksUnlock();
    void printInventory();
    void tradeWithJoja();
    void villagerTrading(vector<Villager> villagers, int vIndex);
    vector<string> donateItem(vector<string> bundle);

};

#endif