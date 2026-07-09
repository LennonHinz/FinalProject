#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "npc.h"

using namespace std;


npc::npc(string n, string l, bool u) {
    name = n;
    location = l;
    unlocked = u;
}

void npc::unlock() {
    unlocked = true;
}

string npc::getName() {
    return name;
}

string npc::getLocation() {
    return location;
}