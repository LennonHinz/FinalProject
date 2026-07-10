#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Player { // the charactor the player is in control of
    private:
    string name;
    string location;
    double averageSleep;
    int gold;
    bool sleepDeprived;

    public:
    string inventory[10];
    Player(string n);
    void setLocation(string l);
    void setAverageSleep(double lN, int day);
    void changeGold(int g);
    string changeInventory(string item, int place);
    string getName();
    string getLocation();
    double getAverageSleep();
    int getGold();
    bool getSleepDeprived();

};

#endif