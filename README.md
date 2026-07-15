# FinalProject

# CSCI 1300 Final Project

## Theme

The theme for my project is Stardew Vally. You must explore the world to complete the final bundle required to save the town.

## Goal

The goal it to complete the bundle before you run out of time while making sure that you leave enough time to sleep.

## How to compile and run

Compile with: g++ -std=c++17 -Wall -Werror -Wpedantic main.cpp Player.cpp npc.cpp Villager.cpp
Run with: ./a.exe

## How to play

To play select different options to move around the map, talk to villegers, and donate to the communite in order to complete the final bundle.

## Classes

Player class keeps track of all of the players resorces. The NPC class is a base class for any npc's. The villager class is build off of the NPC class and controls all villager spacific funcations.

## Extra credit

For the weighted routes I included locations that are locked at the begining of the game and become unlock as you progress. For the bundle planner I included step to complete the current item that the player is currently on.