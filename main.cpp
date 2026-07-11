#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "Player.h"
#include "npc.h"
#include "Villager.h"
#include "Town.h"

using namespace std;

void printTrades(vector<Villager> villagers, int vIndex);

int main() {

    //starting up the game
    string playerName;
    cout << "Enter you players name: ";
    getline(cin, playerName);

    //Create the player
    Player player(playerName);


    int Day = 1;

    //Create all the different villagers
    vector<Villager> villagers;
    Villager Pierre("Pierre", "Town", true, {"Wheat Seeds", "Parsnip Seeds"}, {1, 5}); //Pierre index 0
    villagers.push_back(Pierre);
    Villager Willy("Willy", "Docks", false, {"Cod", "Catfish"}, {3, 10}); //Willy index 1
    villagers.push_back(Willy);
    Villager Clint("Clint", "Mines", false, {"Stone", "Coal", "Iron"}, {1, 5, 15}); //Clint index 2
    villagers.push_back(Clint);

    for (int end = 7; Day <= end; Day++) { // main gameplay loop
        for (int time = 18; time > 0; time--){
            //time = printMenu(villagers, player, Day, time);
            string location = player.getLocation();

    cout << "==================================================" << endl;
    cout << "            THE FINAL BUNDLE" << endl;
    cout << "==================================================" << endl << endl;

    cout << "Day: " << Day << " / 7        Time left in day: " << time << "       Average sleep: " << player.getAverageSleep() << "        Money: " << player.getGold() << " gold" << endl;
    cout << "Location: " << location << endl << endl;

    // include bundle information here

    // include map here

    cout << "Current options: " << endl;

    int decition;

    if (location == "Town") {
        cout << "1) Trade with Pierre" << endl;
        cout << "2) Go to Jojamart" << endl;
        cout << "3) Travel to _____" << endl;
        cout << "4) Pass time" << endl;
        do {
            cout << "Enter you decition: ";
            cin >> decition;
        } while (decition <= 0 && decition > 4);

        switch (decition) {
            case 1:
            printTrades(villagers, 0);
            break;
            case 2:
            cout << "You entered Jojamart" << endl;
            break;
            case 3:
            //main.getPlayer(0).setLocation("dectination") // will finish later
            break;
            case 4:
            break; // starts next hour
            default:
            break;
        }

    }else if (location == "Docks") {
        cout << "1) Trade with Willy" << endl;
        cout << "2) Travel to _____" << endl;
        cout << "3) Pass time" << endl;
        do {
            cout << "Enter you decition: ";
            cin >> decition;
        } while (decition <= 0 && decition > 3);

        switch (decition) {
            case 1:
            printTrades(villagers, 1);
            case 2:
            //main.getPlayer(0).setLocation("dectination") // will finish later
            break;
            case 3:
            break; // starts next hour
            default:
            break;
        }

    }else if (location == "Mines") {
        cout << "1) Trade with Clint" << endl;
        cout << "2) Travel to _____" << endl;
        cout << "3) Pass time" << endl;
        do {
            cout << "Enter you decition: ";
            cin >> decition;
        } while (decition <= 0 && decition > 3);

        switch (decition) {
            case 1:
            printTrades(villagers, 2);
            case 2:
            //main.getPlayer(0).setLocation("dectination") // will finish later
            break;
            case 3:
            break; // starts next hour
            default:
            break;
        }

    }else if (location == "Farm") {
        cout << "1) Travel to _____" << endl;
        cout << "2) Pass time" << endl;
        cout << "3) Plant crop" << endl;
        if (time <= 4) {
            cout << "4) Go to sleep" << endl;
            do {
                cout << "Enter you decition: ";
                cin >> decition;
            } while (decition <= 0 && decition > 4);

            switch (decition) {
            case 1:
            //main.getPlayer(0).setLocation("dectination") // will finish later
            break;
            case 2:
            break; // starts next hour
            case 3:
            break; // in progress
            case 4:
            player.setAverageSleep(time, Day);
            time = 0;
            break;
            default:
            break;
            }

        }else{
            do {
                cout << "Enter you decition: ";
                cin >> decition;
            } while (decition <= 0 && decition > 3);

            switch (decition) {
                case 1:
                //main.getPlayer(0).setLocation("dectination") // will finish later
                case 2:
                break; // starts next hour
                case 3:
                break; // in progress
                default:
                break;
            }
        }
    }

    cout << endl << endl;
        }
    }


    return 0;
}

void printTrades(vector<Villager> villagers, int vIndex) {
    vector<string> trades = villagers[vIndex].getTrades();
    vector<int> prices = villagers[vIndex].getPrices();
    for (int i = 0; i < static_cast<int>(trades.size()); i++) {
        cout << trades[i] << " : " << prices[i] << endl;
    }
}