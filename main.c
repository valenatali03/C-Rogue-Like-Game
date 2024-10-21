#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <ctype.h>

typedef struct Player
{
  int xPosition;
  int yPosition;
  int health;
}Player;


int screenSetUp();
int mapSetUp();
Player * playerSetUp();
int handleInput(int input, Player * player);
int playerMove(int y, int x, Player * player);
int checkPosition(int y, int x, Player * entity);

int main () {
  Player * player;
  int ch;

  screenSetUp();

  mapSetUp();

  player = playerSetUp();

  while ((ch = tolower(getch())) != 'q')
  {
    handleInput(ch, player);
  }
  

  return 0;
}

int screenSetUp() {
  if (initscr() == NULL) {
    fprintf(stderr, "Error inicializando la pantalla\n");
    exit(1);
  }
  printw("Hello world!");
  noecho();
  refresh();

  return 1;
}

int mapSetUp() {
  mvprintw(13, 13, "-------");
  mvprintw(14, 13, "|.....|");
  mvprintw(15, 13, "|.....|");
  mvprintw(16, 13, "|.....|");
  mvprintw(17, 13, "|.....|");
  mvprintw(18, 13, "-------");

  mvprintw(2, 40, "-------");
  mvprintw(3, 40, "|.....|");
  mvprintw(4, 40, "|.....|");
  mvprintw(5, 40, "|.....|");
  mvprintw(6, 40, "|.....|");
  mvprintw(7, 40, "-------");

  mvprintw(10, 40, "-----------");
  mvprintw(11, 40, "|.........|");
  mvprintw(12, 40, "|.........|");
  mvprintw(13, 40, "|.........|");
  mvprintw(14, 40, "|.........|");
  mvprintw(15, 40, "-----------");

  return 1;
}

Player * playerSetUp() {
  Player * newPlayer;
  newPlayer = malloc(sizeof(Player));

  newPlayer->xPosition = 14;
  newPlayer->yPosition = 14;
  newPlayer->health = 20;

  mvprintw(newPlayer->yPosition, newPlayer->xPosition, "@");
  move(newPlayer->yPosition, newPlayer->xPosition);

  return newPlayer;
}

int handleInput(int input, Player * player) {
  int newY;
  int newX;

  switch (input)
  {
  case 'w':
    newY = player->yPosition - 1;
    newX = player->xPosition;
    break;
  
  case 's':
    newY = player->yPosition + 1;
    newX = player->xPosition;
    break;

  case 'a':
    newY = player->yPosition;
    newX = player->xPosition - 1;
    break;

  case 'd':
    newY = player->yPosition;
    newX = player->xPosition + 1;
    break;

  default:
    break;
  }
  
  checkPosition(newY, newX, player);

  return 1;
}

int checkPosition(int y, int x, Player * entity) {
  int space;
  switch (mvinch(y,x))
  {
  case '.':
    playerMove(y, x, entity);
    break;
  
  default:
    move(entity->yPosition, entity->xPosition);
    break;
  }
}

int playerMove(int y, int x, Player * player) {
  mvprintw(player->yPosition, player->xPosition, ".");
  
  player->yPosition = y;
  player->xPosition = x;

  mvprintw(player->yPosition, player->xPosition, "@");
  move(player->yPosition, player->xPosition);

  return 1;
}