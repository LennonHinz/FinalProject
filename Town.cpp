#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "Player.h"
#include "npc.h"
#include "Villager.h"
#include "Town.h"

using namespace std;

void Town::addVillager(Villager v) {
    villagers.push_back(v);
}

Town::Town(Player p) : player(p) {}

Villager Town::getVillagers(int index) {
    return villagers[index];
}

Player Town::getPlayer() {
    return player;
}