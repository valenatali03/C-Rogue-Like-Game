#ifndef ROGUE_H
#define ROGUE_H

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

typedef struct Level
{
    char **tiles;
    int level;
    int sizeRooms;
    struct Room **rooms;
    struct Monset **monsters;
    int sizeMonsters;
} Level;

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

typedef struct Monster
{
    char symbol;
    int health;
    int attack;
    int speed;
    int defence;
    int pathfinding;
    Position position;
}Monster;

int screenSetUp();

/*level/Map functions*/
Level *createLevel(int level);
Room **roomSetUp();

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

/* Monter functions*/
int addMonsters(Level * level);
Monster * selectMonster(int level);
Monster * createMonster(char symbol, int health, int attack, int speed, int defence, int pathfinding);
int setStartingPosition(Monster * monster, Room * room);

/*Aux*/
bool is_closer(int current, int target, int new_position);
bool is_empty_space(int y, int x);

#endif