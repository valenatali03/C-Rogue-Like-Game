#include "rogue.h"

Player *playerSetUp()
{
    Player *newPlayer;
    newPlayer = malloc(sizeof(Player));

    newPlayer->position.x = 14;
    newPlayer->position.y = 14;
    newPlayer->health = 20;

    mvprintw(newPlayer->position.y, newPlayer->position.x, "@");
    move(newPlayer->position.y, newPlayer->position.x);

    return newPlayer;
}

int handleInput(int input, Player *player)
{
    int newY;
    int newX;

    switch (input)
    {
    case 'w':
        newY = player->position.y - 1;
        newX = player->position.x;
        break;

    case 's':
        newY = player->position.y + 1;
        newX = player->position.x;
        break;

    case 'a':
        newY = player->position.y;
        newX = player->position.x - 1;
        break;

    case 'd':
        newY = player->position.y;
        newX = player->position.x + 1;
        break;

    default:
        break;
    }

    checkPosition(newY, newX, player);

    return 1;
}

int checkPosition(int y, int x, Player *entity)
{
    int space;
    switch (mvinch(y, x))
    {
    case '+':
    case '#':
    case '.':
        playerMove(y, x, entity);
        break;

    default:
        move(entity->position.y, entity->position.x);
        break;
    }
}

int playerMove(int y, int x, Player *player)
{
    mvprintw(player->position.y, player->position.x, ".");

    player->position.y = y;
    player->position.x = x;

    mvprintw(player->position.y, player->position.x, "@");
    move(player->position.y, player->position.x);

    return 1;
}