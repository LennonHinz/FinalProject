#ifndef NPC_H
#define NPC_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class npc {
    private:
    string name;
    string location;
    bool unlocked;

    public:
    npc(string n, string l, bool u);
    void unlock();
    string getName();
    string getLocation();

};

#endif