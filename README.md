# FinalProject

# CSCI 1300 Final Project

## Theme

The theme for my project is Stardew Valley. You must explore the world to complete the final bundle required to save the town.

## Goal

The goal it to complete the bundle before you run out of time while making sure that you leave enough time to sleep.

## How to compile and run

Compile with: g++ -std=c++17 main.cpp Player.cpp npc.cpp Villager.cpp
Run with: ./a.exe

## How to play

To play select different options to move around the map, talk to villagers, and donate to the community in order to complete the final bundle.

## Classes

Player class keeps track of all of the players resorces. The NPC class is a base class for any npc's. The villager class is built off of the NPC class and controls all villager specific functions.

## Extra credit

For the weighted routes I included locations that are locked at the beginning of the game and become unlocked as you progress. For the bundle planner I included steps to complete the item that the player is currently on.