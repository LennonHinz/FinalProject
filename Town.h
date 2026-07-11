#ifndef TOWN_H
#define TOWN_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "Player.h"
#include "npc.h"
#include "Villager.h"

using namespace std;

class Town {
    private:
    vector<Villager> villagers;
    Player player;
    
    public:
    void addVillager(Villager v);
    Town (Player p);
    Villager getVillagers(int index);
    Player getPlayer();

};

#endif