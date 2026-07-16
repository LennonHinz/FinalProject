#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#include "Player.h"
#include "npc.h"
#include "Villager.h"

using namespace std;

void bundlePlanner(string nextItem);

int main() {

    //starting up the game
    string playerName;
    cout << "Enter you players name: ";
    getline(cin, playerName);

    //Create the player
    Player player(playerName);

    //Create Bundle
    vector<string> bundle = {"Pork", "Parsnip", "Coal", "Log", "Catfish"};

    int Day = 1;
    vector<string> farm;

    //Create all the different villagers
    vector<Villager> villagers;
    Villager Pierre("Pierre", "Town", {"Wheat seed", "Parsnip seed"}, {5, 10}); //Pierre index 0
    villagers.push_back(Pierre);
    Villager Willy("Willy", "Docks", {"Cod", "Catfish"}, {5, 15}); //Willy index 1
    villagers.push_back(Willy);
    Villager Clint("Clint", "Mines", {"Stone", "Coal", "Iron"}, {5, 10, 20}); //Clint index 2
    villagers.push_back(Clint);
    Villager Marnie("Marnie", "Marnie's Ranch", {"Chicken", "Beef", "Pork"}, {5, 10, 15}); //Marnie index 3
    villagers.push_back(Marnie);

    // Print rules
    cout << endl << "Rules:" << endl;
    cout << "1) Collect all of the items required to complete the bundle and donate them to the Community before the end of the week to win" << endl;
    cout << "2) Trading with villagers allows you to buy things from them for gold and talking to them allows you to give them items for a reward" << endl;
    cout << "3) Completing tasks can also unlock paths to new locations that can be found on the map" << endl;
    cout << "4) Trading with Joja gives you a shortcut but downgrades the difficulty of your run" << endl;
    cout << "5) If you need help figuring out what to do next, you can access the bundle planner at your Farm" << endl;
    cout << "6) By the time you complete the final bundle you must have maintained an average of 8 hours of sleep per night" << endl;
    cout << "7) You can go to bed starting at 8 each night unless you have traded with Joja then you can't go to bed until 9" << endl;
    cout << "8) You are not allowed to stay out past midnight and you wake up every morning at 6" << endl;
    cout << "9) If you plant a seed the crop will be ready for you the next day in your inventory" << endl;
    cout << "10) Have fun and good luck" << endl << endl;

    for (int end = 7; Day <= end; Day++) { // main gameplay loop
        for (int time = 18; time >= 0; time--){
            //time = printMenu(villagers, player, Day, time);
            string location = player.getLocation();

            cout << "==================================================" << endl;
            cout << "            THE FINAL BUNDLE" << endl;
            cout << "==================================================" << endl << endl;

            cout << "Day: " << Day << " / 7        Time left in day: " << time << "       Average sleep: " << player.getAverageSleep() << "        Money: " << player.getGold() << " gold" << endl;
            cout << "Joja Influence: " << player.getJojaInfluence() << endl << endl << endl;

            cout << "Map:" << endl << endl;
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

            cout << "Current location: " << location << endl << endl << endl;

            player.printInventory();

            // include bundle information here
            cout << "Items left in bundle:" << endl;
            for (int i = 0; i < static_cast<int>(bundle.size()); i++) {
                cout << bundle[i] << endl;
            }

            cout << endl << "Current options: " << endl;

            int decision;

            if (location == "Town") {
                cout << "1) Trade with Pierre" << endl;
                cout << "2) Travel to Jojamart" << endl;
                cout << "3) Travel to the Community Center" << endl;
                cout << "4) Travel to your Farm" << endl;
                cout << "5) Pass time" << endl;
                do {
                    cout << "Enter you decision: ";
                    cin >> decision;
                } while (decision <= 0 || decision > 5);

                switch (decision) {
                    case 1:
                    player.villagerTrading(villagers, 0);
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
                    cout << "Enter you decision: ";
                    cin >> decision;
                } while (decision <= 0 || decision > 3);

                switch (decision) {
                    case 1:
                    player.villagerTrading(villagers, 1);
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
                cout << "2) Talk to Timmy" << endl;
                cout << "3) Travel to the Community Center" << endl;
                if (player.getDocksUnlock()) {
                    cout << "4) Travel to Docks" << endl;
                    cout << "5) Pass time" << endl;
                    do {
                        cout << "Enter you decision: ";
                        cin >> decision;
                    } while (decision <= 0 || decision > 5);

                    switch (decision) {
                        case 1:
                        player.villagerTrading(villagers, 2);
                        break;
                        case 2:
                        int choice;
                        cout << endl << endl << "I need a piece of wheat" << endl;
                        cout << "1) Give Timmy a piece of wheat" << endl;
                        cout << "2) Stop talking to Timmy" << endl;

                        do {
                        cout << "Enter you decision: ";
                        cin >> choice;
                        } while (choice <= 0 || choice > 2);

                        if (choice == 1) {
                            if (player.findItem("Wheat")) {
                                player.removeInventory("Wheat");
                                player.UnlockDocks();
                                player.changeGold(20);
                                cout << "Thank you for the Wheat : I have given you 20 gold and unlocked the Docks for you" << endl;
                            }else{
                                cout << endl << "You do not have a wheat" << endl;
                            }
                        }
                        break;
                        case 3:
                        player.setLocation("Community Center");
                        break;
                        case 4:
                        player.setLocation("Docks");
                        break;
                        case 5:
                        break; // starts next hour
                        default:
                        break;
                    }
                }else{
                    cout << "4) Pass time" << endl;
                    cout << "Docks are currently locked" << endl;
                    do {
                        cout << "Enter you decision: ";
                        cin >> decision;
                    } while (decision <= 0 || decision > 4);

                    switch (decision) {
                        case 1:
                        player.villagerTrading(villagers, 2);
                        break;
                        case 2:
                        int choice;
                        cout << endl << endl << "I need a piece of wheat" << endl;
                        cout << "1) Give Timmy a piece of wheat" << endl;
                        cout << "2) Stop talking to Timmy" << endl;

                        do {
                        cout << "Enter you decision: ";
                        cin >> choice;
                        } while (choice <= 0 || choice > 2);

                        if (choice == 1) {
                            if (player.findItem("Wheat")) {
                                player.removeInventory("Wheat");
                                player.UnlockDocks();
                                player.changeGold(20);
                                cout << "Thank you for the Wheat : I have given you 20 gold and unlocked the Docks for you" << endl;
                            }else{
                                cout << endl << "You do not have a wheat" << endl;
                            }
                        }
                        break;
                        case 3:
                        player.setLocation("Community Center");
                        break;
                        case 4:
                        break; // starts next hour
                        default:
                        break;
                    }
                }
            }else if (location == "Farm") {
                int bedTime = 4;
                if (player.getJojaInfluence() >= 1) {
                    bedTime = 3;
                }
                cout << "1) Travel to Town" << endl;
                cout << "2) Travel to Forest" << endl;
                cout << "3) View bundle planner" << endl;
                cout << "4) Pass time" << endl;
                cout << "5) Plant crop" << endl;
                if (time <= bedTime) {
                    cout << "6) Go to sleep" << endl;
                    do {
                        cout << "Enter you decision: ";
                        cin >> decision;
                    } while (decision <= 0 || decision > 6);

                    switch (decision) {
                    case 1:
                    player.setLocation("Town");
                    break;
                    case 2:
                    player.setLocation("Forest");
                    break;
                    case 3:
                    bundlePlanner(bundle[0]);
                    break;
                    case 4:
                    break; // starts next hour
                    case 5:
                    int choice;
                    cout << endl << endl << "What seeds do you want to plant?" << endl;
                    cout << "1) Wheat seed" << endl;
                    cout << "2) Parsnip seed" << endl;
                    cout << "3) Stop planting" << endl;

                    do {
                    cout << "Enter you decision: ";
                    cin >> choice;
                    } while (choice <= 0 || choice > 3);

                    if (choice == 1) {
                        if (player.findItem("Wheat seed")) {
                            player.removeInventory("Wheat seed");
                            farm.push_back("Wheat seed");
                            cout << "The wheat will be ready tomorrow" << endl;
                        }else {
                            cout << endl << "You do not have a wheat seed" << endl;
                        }
                    }else if (choice == 2) {
                        if (player.findItem("Parsnip seed")) {
                            player.removeInventory("Parsnip seed");
                            farm.push_back("Parsnip seed");
                            cout << "The parsnip will be ready tomorrow" << endl;
                        }else {
                            cout << endl << "You do not have a parsnip seed" << endl;
                        }
                    }
                    break;
                    case 6:
                    player.setAverageSleep(time, Day);
                    time = -1;
                    break;
                    default:
                    break;
                    }

                }else{
                    do {
                        cout << "Enter you decision: ";
                        cin >> decision;
                    } while (decision <= 0 || decision > 5);

                    switch (decision) {
                        case 1:
                        player.setLocation("Town");
                        break;
                        case 2:
                        player.setLocation("Forest");
                        break;
                        case 3:
                        bundlePlanner(bundle[0]);
                        break;
                        case 4:
                        break; // starts next hour
                        case 5:
                        int choice;
                        cout << endl << endl << "What seeds do you want to plant?" << endl;
                        cout << "1) Wheat seed" << endl;
                        cout << "2) Parsnip seed" << endl;
                        cout << "3) Stop planting" << endl;

                        do {
                        cout << "Enter you decision: ";
                        cin >> choice;
                        } while (choice <= 0 || choice > 3);

                        if (choice == 1) {
                            if (player.findItem("Wheat seed")) {
                                player.removeInventory("Wheat seed");
                                farm.push_back("Wheat seed");
                                cout << "The wheat will be ready tomorrow" << endl;
                            }else {
                                cout << endl << "You do not have a wheat seed" << endl;
                            }
                        }else if (choice == 2) {
                            if (player.findItem("Parsnip seed")) {
                                player.removeInventory("Parsnip seed");
                                farm.push_back("Parsnip seed");
                                cout << "The parsnip will be ready tomorrow" << endl;
                            }else {
                                cout << endl << "You do not have a parsnip seed" << endl;
                            }
                        }
                        break;
                        default:
                        break;
                    }
                }
            }else if (location == "Forest") {
                cout << "1) Talk to Ned" << endl;
                cout << "2) Chop wood" << endl;
                cout << "3) Search for treasure (3 hours)" << endl;
                cout << "4) Travel to your Farm" << endl;
                cout << "5) Pass time" << endl;
                do {
                    cout << "Enter you decision: ";
                    cin >> decision;
                } while (decision <= 0 || decision > 5);

                switch (decision) {
                    case 1:
                    int choice;
                    cout << endl << endl << "I need a piece of parsnip" << endl;
                    cout << "1) Give Ned a piece of Parsnip" << endl;
                    cout << "2) Stop talking to Ned" << endl;

                    do {
                    cout << "Enter you decision: ";
                    cin >> choice;
                    } while (choice <= 0 || choice > 2);

                    if (choice == 1) {
                        if (player.findItem("Parsnip")) {
                            player.removeInventory("Parsnip");
                            player.changeGold(30);
                            cout << "Thank you for the Parsnip : I have given you 30 gold" << endl;
                        }else{
                            cout << endl << "You do not have a Parsnip" << endl;
                        }
                    }
                    break;
                    case 2:
                    if (player.findItem("Axe")){
                        player.addInventory("Log");
                    }else{
                        cout << "You dont have an axe : couldn't chop wood" << endl;
                    }
                    break;
                    case 3:
                    if (time <= 3) {
                        time = 0;
                    }
                    time = time - 2;
                    player.addInventory("Vase");
                    break;
                    case 4:
                    player.setLocation("Farm");
                    break;
                    case 5:
                    break; // starts next hour
                    default:
                    break;
                }
            }else if (location == "JojaMart") {
                cout << "1) Trade with Joja" << endl;
                cout << "2) Travel to Town" << endl;
                cout << "3) Pass time" << endl;
                do {
                    cout << "Enter you decision: ";
                    cin >> decision;
                } while (decision <= 0 || decision > 3);

                switch (decision) {
                    case 1:
                    bundle = player.tradeWithJoja(bundle);
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
                cout << "3) Travel to Marnie's Ranch" << endl;
                if (player.getMinesUnlock()) {
                    cout << "4) Travel to Mines" << endl;
                    cout << "5) Pass time" << endl;
                    do {
                        cout << "Enter you decision: ";
                        cin >> decision;
                    } while (decision <= 0 || decision > 5);

                    switch (decision) {
                        case 1:
                        bundle = player.donateItem(bundle);
                        break;
                        case 2:
                        player.setLocation("Town");
                        break;
                        case 3:
                        player.setLocation("Marnie's Ranch");
                        break;
                        case 4:
                        player.setLocation("Mines");
                        break;
                        case 5:
                        break; // starts next hour
                        default:
                        break;
                    }
                }else{
                    cout << "4) Pass time" << endl;
                    cout << "Mines are currently locked" << endl;
                    do {
                        cout << "Enter you decision: ";
                        cin >> decision;
                    } while (decision <= 0 || decision > 4);

                    switch (decision) {
                        case 1:
                        bundle = player.donateItem(bundle);
                        break;
                        case 2:
                        player.setLocation("Town");
                        break;
                        case 3:
                        player.setLocation("Marnie's Ranch");
                        break;
                        case 4:
                        break; // starts next hour
                        default:
                        break;
                    }
                }
            }else if (location == "Marnie's Ranch") {
                cout << "1) Trade with Marnie" << endl;
                cout << "2) Talk to Bill" << endl;
                cout << "3) Travel to the Community Center" << endl;
                cout << "4) Travel to the Blacksmith" << endl;
                cout << "5) Pass time" << endl;
                do {
                    cout << "Enter you decision: ";
                    cin >> decision;
                } while (decision <= 0 || decision > 5);

                switch (decision) {
                    case 1:
                    player.villagerTrading(villagers, 3);
                    break;
                    case 2:
                    int choice;
                    cout << endl << endl << "I need a vase for my house" << endl;
                    cout << "1) Give Bill a vase" << endl;
                    cout << "2) Stop talking to Bill" << endl;

                    do {
                    cout << "Enter you decision: ";
                    cin >> choice;
                    } while (choice <= 0 || choice > 2);

                    if (choice == 1) {
                        if (player.findItem("Vase")) {
                            player.removeInventory("Vase");
                            player.UnlockMines();
                            player.changeGold(20);
                            cout << "Thank you for the vase : I have given you 20 gold and unlocked the Mines for you" << endl;
                        }else{
                            cout << endl << "You do not have a vase" << endl;
                        }
                    }
                    break;
                    case 3:
                    player.setLocation("Community Center");
                    break;
                    case 4:
                    player.setLocation("Blacksmith");
                    break;
                    case 5:
                    break; // starts next hour
                    default:
                    break;
                }
            }else if (location == "Blacksmith") {
                cout << "1) Talk to Tom" << endl;
                cout << "2) Travel to Marnie's Ranch" << endl;
                cout << "3) Pass time" << endl;
                do {
                    cout << "Enter you decision: ";
                    cin >> decision;
                } while (decision <= 0 || decision > 3);

                switch (decision) {
                    case 1:
                    int choice;
                    cout << endl << endl << "I need iron to make an axe. If you have one I will give you the axe." << endl;
                    cout << "1) Give Tom iron" << endl;
                    cout << "2) Stop talking to Tom" << endl;

                    do {
                    cout << "Enter you decision: ";
                    cin >> choice;
                    } while (choice <= 0 || choice > 2);

                    if (choice == 1) {
                        if (player.findItem("Iron")) {
                            player.removeInventory("Iron");
                            player.addInventory("Axe");
                            cout << "Thank you for the Iron : I have given you an axe" << endl;
                        }else{
                            cout << endl << "You do not have a vase" << endl;
                        }
                    }
                    break;
                    case 2:
                    player.setLocation("Marnie's Ranch");
                    break;
                    case 3:
                    break; // starts next hour
                    default:
                    break;
                }
            }
            cout << endl << endl;

            if (0 == static_cast<int>(bundle.size())) { // Win/Loss conditions
                if (8 > player.getAverageSleep()) {
                    cout << player.getName() << " didn't get enough sleep" << endl << "Game Over : You Lost" << endl;
                    return 0;
                }
                if (player.getJojaInfluence() == 0) {
                    cout << "Congratulations!!! " << player.getName() << " completed the bundle in time : Joja Influence: " << player.getJojaInfluence() << endl << "Game Over : You Won" << endl;
                    return 0;
                }else if (player.getJojaInfluence() == 1) {
                    cout << "Congratulations!!! " << player.getName() << " completed the bundle in time, however you had some infuence from Joja : Joja Influence: " << player.getJojaInfluence() << endl << "Game Over : You Won" << endl;
                    return 0;
                }else if (player.getJojaInfluence() >= 2){
                    cout << "Congratulations!!! " << player.getName() << " completed the bundle in time, however you had a lot of infuence from Joja : Joja Influence: " << player.getJojaInfluence() << endl << "Game Over : You Won" << endl;
                    return 0;
                }
            }

            if (time == 0) {
                cout << player.getName() << " stayed out to late : Joja Influence: " << player.getJojaInfluence() << endl << "Game Over : You Lost" << endl;
                return 0;
            } 
        }
        for (int i = 0; i < static_cast<int>(farm.size()); i++) { // growing crops
            cout << farm.size();
            if (farm[i] == "Wheat seed") {
                player.addInventory("Wheat");
                farm.erase(farm.begin() + i);
                i--;
            }else if (farm[i] == "Parsnip seed") {
                player.addInventory("Parsnip");
                farm.erase(farm.begin() + i);
                i--;
            }
        }
    }

    if (0 != static_cast<int>(bundle.size())) {
        if (8 > player.getAverageSleep()) {
            cout << player.getName() << " didn't complete the bundle in time and didn't get enough sleep : Joja Influence: " << player.getJojaInfluence() << endl << "Game Over : You Lost" << endl;
            return 0;
        }
        cout << player.getName() << " didn't complete the bundle in time : Joja Influence: " << player.getJojaInfluence() << endl << "Game Over : You Lost" << endl;
        return 0;
    }

    if (8 > player.getAverageSleep()) {
        cout << player.getName() << " didn't get enough sleep : Joja Influence: " << player.getJojaInfluence() << endl << "Game Over : You Lost" << endl;
        return 0;
    }

    if (player.getJojaInfluence() == 0) {
        cout << "Congratulations!!! " << player.getName() << " completed the bundle in time : Joja Influence: " << player.getJojaInfluence() << endl << "Game Over : You Won" << endl;
        return 0;
    }else if (player.getJojaInfluence() == 1) {
        cout << "Congratulations!!! " << player.getName() << " completed the bundle in time, however you had some infuence from Joja : Joja Influence: " << player.getJojaInfluence() << endl << "Game Over : You Won" << endl;
        return 0;
    }else if (player.getJojaInfluence() >= 2){
        cout << "Congratulations!!! " << player.getName() << " completed the bundle in time, however you had a lot of infuence from Joja : Joja Influence: " << player.getJojaInfluence() << endl << "Game Over : You Won" << endl;
        return 0;
    }
    return 0;
}

void bundlePlanner(string nextItem) {
    cout << endl << "Steps:" << endl;
    if (nextItem == "Pork") {
        cout << "Buy pork from Marnie at Marnie's Ranch" << endl;
    }else if (nextItem == "Parsnip") {
        cout << "Buy a parsnip seed from Pierre in town" << endl;
        cout << "Go back to your farm to plant the seed" << endl;
        cout << "Wait till the next day and the parsnip will be ready" << endl;
    }else if (nextItem == "Coal") {
        cout << "Find the vase in the forest" << endl;
        cout << "Give the vase to Bill at Marnie's Ranch to unlock the Mines" << endl;
        cout << "Buy coal from Clint at the Mines" << endl;
    }else if (nextItem == "Log") {
        cout << "Buy iron from Clint at the Mines" << endl;
        cout << "Give the iron to Tom at the Blacksmith to recive an axe in return" << endl;
        cout << "Go to the forest to chop a log" << endl;
    }else if (nextItem == "Catfish") {
        cout << "Buy a wheat seed from Pierre in town" << endl;
        cout << "Go back to your farm to plant the seed" << endl;
        cout << "Wait till the next day and for the wheat to be ready" << endl;
        cout << "Give the wheat to Timmy at the Mines to unlock the docks" << endl;
        cout << "Buy a catfish from Willy at the Docks" << endl;
    }
}