# Project Description

## Theme

I am going to stick to the Stardew Valley theme.

## Classes

I will make classes to help store and track the player, items, characters, locations, bundle, and inventory.

## Limited resource

Along with time I will also use amount of sleep and money as a limited resource that the player has to manage.

## Handling time

I will handle time by tracking days until the end of the season and the player must finish the bundle before this time.

## Extra Credit

For extra credit I am planning on implementing a weather system that effects gameplay and the smarter bundle planner.

### EC Descriptions

I will make a weather system and with it give the player a forecast so that they are able to plan ahead for the positives and negatives that different weather will cause. I will also add the planner that will check what the player still has left to complete and based on that information give recommendations of what they should do next.

## Tradeoff system

You will be able to trade with Joja throughout the game for things like items required for the bundle or unlocking new locations. However this will come at a cost like villages giving you less favorable deals or a cap on the number of hours you can rest each night.

## Mapping style

I will use a connected location map and location marker like the one from the example below:

        [Mines]
            |
[Farm] -- [Town Square] -- [Community Center] -- [Beach]
   |            |
[Forest]     [Pierre's]

You are here at _____


## Win/lose condition

The primary win/lose condition will be whether or not the player completed the bundle along with a weighting of how you won based on your dependence on Joja. There will also be a way to lose early with things like exhaustion.