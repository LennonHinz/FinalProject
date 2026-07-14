#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "npc.h"

using namespace std;


npc::npc(string n, string l) {
    name = n;
    location = l;
}

string npc::getName() {
    return name;
}

string npc::getLocation() {
    return location;
}