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

    public:
    npc(string n, string l);
    string getName();
    string getLocation();

};

#endif