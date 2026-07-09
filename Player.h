#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Player {
    private:
    string name;
    double averageSleep;
    int gold;
    bool sleepDeprived;

    public:
    string inventory[10];
    Player(string n);
    void setAverageSleep(double lN, int day);
    void changeGold(int g);
    string changeInventory(string item, int place);
    string getName();
    double getAverageSleep();
    int getGold();
    bool getSleepDeprived();

};

#endif