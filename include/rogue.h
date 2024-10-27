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
Room **mapSetUp();
Player *playerSetUp();
int handleInput(int input, Player *player);
int playerMove(int y, int x, Player *player);
int checkPosition(int y, int x, Player *entity);
int connectDoors(Position *doorOne, Position *doorTwo);

/*Aux*/
bool is_closer(int current, int target, int new_position);
bool is_empty_space(int y, int x);

/*room functions*/
Room *createRoom(int x, int y, int height, int width);
int drawRoom(Room *room);

#endif