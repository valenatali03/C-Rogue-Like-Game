#ifndef ROGUE_H
#define ROGUE_H

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

typedef struct Position
{
    int x;
    int y;
    // TILE_TYPE tile;
} Position;

typedef struct Room
{
    Position position;
    int height;
    int width;

    Position **doors;
    // Monster ** monsters;
    // Item ** items;
} Room;

typedef struct Player
{
    Position position;
    int health;
} Player;

int screenSetUp();

/*level/Map functions*/
Room **mapSetUp();

/*Players functions*/
Player *playerSetUp();
Position *handleInput(int input, Player *player);
int playerMove(Position *newPosition, Player *player, char **level);
int checkPosition(Position *newPosition, Player *entity, char **level);

/*room functions*/
Room *createRoom(int x, int y, int height, int width);
int drawRoom(Room *room);
int connectDoors(Position *doorOne, Position *doorTwo);
char **saveLevelPositions();

/*Aux*/
bool is_closer(int current, int target, int new_position);
bool is_empty_space(int y, int x);

#endif