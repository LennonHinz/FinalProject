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
    int getJojaInfluence();
    void UnlockMines();
    bool getMinesUnlock();
    void UnlockDocks();
    bool getDocksUnlock();
    bool findItem(string item);
    void addInventory(string i);
    void removeInventory(string item);
    void printInventory();
    vector<string> tradeWithJoja(vector<string> bundle);
    void villagerTrading(vector<Villager> villagers, int vIndex);
    vector<string> donateItem(vector<string> bundle);

};

#endif