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

Position * handleInput(int input, Player *player)
{
    Position * newPosition;
    newPosition = malloc(sizeof(Position));

    switch (input)
    {
    case 'w':
        newPosition->y = player->position.y - 1;
        newPosition->x = player->position.x;
        break;

    case 's':
        newPosition->y = player->position.y + 1;
        newPosition->x = player->position.x;
        break;

    case 'a':
        newPosition->y = player->position.y;
        newPosition->x = player->position.x - 1;
        break;

    case 'd':
        newPosition->y = player->position.y;
        newPosition->x = player->position.x + 1;
        break;

    default:
        break;
    }

    return newPosition;
}

int checkPosition(Position *newPosition, Player *entity)
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

int playerMove(Position *newPosition, Player *player)
{
    mvprintw(player->position.y, player->position.x, ".");

    player->position.y = y;
    player->position.x = x;

    mvprintw(player->position.y, player->position.x, "@");
    move(player->position.y, player->position.x);

    return 1;
}