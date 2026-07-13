#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#include "Player.h"
#include "npc.h"
#include "Villager.h"

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

            cout << "Day: " << Day << " / 7        Time left in day: " << time << "       Average sleep: " << player.getAverageSleep() << "        Money: " << player.getGold() << " gold" << endl << endl << endl;


            // include map here
            ifstream inFile("Map.txt");
            string line;

            if (inFile.is_open()) {
                while (getline(inFile, line)) {
                    cout << line << endl;
                }

                inFile.close();
            }else{
                cout << "Could not print map" << endl;
            }

            cout << "Current location: " << location << endl << endl;

            // include bundle information here

            cout << endl << "Current options: " << endl;

            int decition;

            if (location == "Town") {
                cout << "1) Trade with Pierre" << endl;
                cout << "2) Travel to Jojamart" << endl;
                cout << "3) Travel to the Community Center" << endl;
                cout << "4) Travel to your Farm" << endl;
                cout << "5) Pass time" << endl;
                do {
                    cout << "Enter you decition: ";
                    cin >> decition;
                } while (decition <= 0 && decition > 4);

                switch (decition) {
                    case 1:
                    printTrades(villagers, 0);
                    break;
                    break;
                    case 2:
                    player.setLocation("JojaMart");
                    break;
                    case 3:
                    player.setLocation("Community Center");
                    break;
                    case 4:
                    player.setLocation("Farm");
                    break;
                    case 5:
                    break; // starts next hour
                    default:
                    break;
                }

            }else if (location == "Docks") {
                cout << "1) Trade with Willy" << endl;
                cout << "2) Travel to the Mines" << endl;
                cout << "3) Pass time" << endl;
                do {
                    cout << "Enter you decition: ";
                    cin >> decition;
                } while (decition <= 0 && decition > 3);

                switch (decition) {
                    case 1:
                    printTrades(villagers, 1);
                    break;
                    case 2:
                    player.setLocation("Mines");
                    break;
                    case 3:
                    break; // starts next hour
                    default:
                    break;
                }

            }else if (location == "Mines") {
                cout << "1) Trade with Clint" << endl;
                cout << "2) Travel to Community Center" << endl;
                if (player.getDocksUnlock()) {
                    cout << "3) Travel to Docks" << endl;
                    cout << "4) Pass time" << endl;
                    do {
                        cout << "Enter you decition: ";
                        cin >> decition;
                    } while (decition <= 0 && decition > 3);

                    switch (decition) {
                        case 1:
                        printTrades(villagers, 2);
                        break;
                        case 2:
                        player.setLocation("Community Center");
                        break;
                        case 3:
                        player.setLocation("Docks");
                        break;
                        case 4:
                        break; // starts next hour
                        default:
                        break;
                    }
                }else{
                    cout << "3) Pass time" << endl;
                    do {
                        cout << "Enter you decition: ";
                        cin >> decition;
                    } while (decition <= 0 && decition > 3);

                    switch (decition) {
                        case 1:
                        printTrades(villagers, 2);
                        break;
                        case 2:
                        player.setLocation("Community Center");
                        break;
                        case 3:
                        break; // starts next hour
                        default:
                        break;
                    }
                }
            }else if (location == "Farm") {
                cout << "1) Travel to Town" << endl;
                cout << "2) Travel to Forest" << endl;
                cout << "3) Pass time" << endl;
                cout << "4) Plant crop" << endl;
                if (time <= 4) {
                    cout << "5) Go to sleep" << endl;
                    do {
                        cout << "Enter you decition: ";
                        cin >> decition;
                    } while (decition <= 0 && decition > 4);

                    switch (decition) {
                    case 1:
                    player.setLocation("Town");
                    break;
                    case 2:
                    player.setLocation("Forest");
                    break;
                    case 3:
                    break; // starts next hour
                    case 4:
                    break; // in progress
                    case 5:
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
                        player.setLocation("Town");
                        break;
                        case 2:
                        player.setLocation("Forest");
                        break;
                        case 3:
                        break; // starts next hour
                        case 4:
                        break; // in progress
                        default:
                        break;
                    }
                }
            }else if (location == "Forest") {
                cout << "1) Chop wood" << endl;
                cout << "2) Travel to your Farm" << endl;
                cout << "3) Pass time" << endl;
                do {
                    cout << "Enter you decition: ";
                    cin >> decition;
                } while (decition <= 0 && decition > 3);

                switch (decition) {
                    case 1:
                    // Chop wood code
                    break;
                    case 2:
                    player.setLocation("Farm");
                    break;
                    case 3:
                    break; // starts next hour
                    default:
                    break;
                }
            }else if (location == "JojaMart") {
                cout << "1) Trade with Joja" << endl;
                cout << "2) Travel to your Town" << endl;
                cout << "3) Pass time" << endl;
                do {
                    cout << "Enter you decition: ";
                    cin >> decition;
                } while (decition <= 0 && decition > 3);

                switch (decition) {
                    case 1:
                    player.tradeWithJoja();
                    break;
                    case 2:
                    player.setLocation("Town");
                    break;
                    case 3:
                    break; // starts next hour
                    default:
                    break;
                }
            }else if (location == "Community Center") {
                cout << "1) Donate to the community" << endl;
                cout << "2) Travel to Town" << endl;
                if (player.getMinesUnlock()) {
                    cout << "3) Travel to Mines" << endl;
                    cout << "4) Pass time" << endl;
                    do {
                        cout << "Enter you decition: ";
                        cin >> decition;
                    } while (decition <= 0 && decition > 3);

                    switch (decition) {
                        case 1:
                        // Donating to bundle functionallity
                        break;
                        case 2:
                        player.setLocation("Town");
                        break;
                        case 3:
                        player.setLocation("Mines");
                        break;
                        case 4:
                        break; // starts next hour
                        default:
                        break;
                    }
                }else{
                    cout << "3) Pass time" << endl;
                    do {
                        cout << "Enter you decition: ";
                        cin >> decition;
                    } while (decition <= 0 && decition > 3);

                    switch (decition) {
                        case 1:
                        // Donating to bundle functionallity
                        break;
                        case 2:
                        player.setLocation("Town");
                        break;
                        case 3:
                        break; // starts next hour
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