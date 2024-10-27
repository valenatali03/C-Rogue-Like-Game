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

Position *handleInput(int input, Player *player)
{
    Position *newPosition;
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

int checkPosition(Position *newPosition, Player *entity, char **level)
{
    int space;
    switch (mvinch(newPosition->y, newPosition->x))
    {
    case '+':
    case '#':
    case '.':
        playerMove(newPosition, entity, level);
        break;

    default:
        move(entity->position.y, entity->position.x);
        break;
    }
}

int playerMove(Position *newPosition, Player *player, char **level)
{
    char buffer[8];

    char aux = level[player->position.y][player->position.x];

    sprintf(buffer, "%c", aux);

    mvprintw(player->position.y, player->position.x, buffer);

    player->position.y = newPosition->y;
    player->position.x = newPosition->x;

    mvprintw(player->position.y, player->position.x, "@");
    move(player->position.y, player->position.x);

    return 1;
}