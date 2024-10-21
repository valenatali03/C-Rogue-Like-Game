#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <ctype.h>

typedef struct Position
{
  int x;
  int y;
  // TILE_TYPE tile;
}Position;


typedef struct Room
{
  Position position;
  int height;
  int width;
  //Monster ** monsters;
  //Item ** items;
}Room;


typedef struct Player
{
  Position position;
  int health;
}Player;

int screenSetUp();
Room ** mapSetUp();
Player * playerSetUp();
int handleInput(int input, Player * player);
int playerMove(int y, int x, Player * player);
int checkPosition(int y, int x, Player * entity);

/*room functions*/
Room * createRoom(int x, int y, int height, int width);
int drawRoom(Room * room);

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

Room ** mapSetUp() {
  Room ** rooms;
  rooms = malloc(sizeof(Room)*6);

  /*mvprintw(13, 13, "-------");
  mvprintw(14, 13, "|.....|");
  mvprintw(15, 13, "|.....|");
  mvprintw(16, 13, "|.....|");
  mvprintw(17, 13, "|.....|");
  mvprintw(18, 13, "-------");*/

  rooms[0] = createRoom(13, 13, 6, 7);
  drawRoom(rooms[0]);

  /*mvprintw(2, 40, "-------");
  mvprintw(3, 40, "|.....|");
  mvprintw(4, 40, "|.....|");
  mvprintw(5, 40, "|.....|");
  mvprintw(6, 40, "|.....|");
  mvprintw(7, 40, "-------");*/

  rooms[1] = createRoom(40, 2, 6, 7);
  drawRoom(rooms[1]);

  /*mvprintw(10, 40, "-----------");
  mvprintw(11, 40, "|.........|");
  mvprintw(12, 40, "|.........|");
  mvprintw(13, 40, "|.........|");
  mvprintw(14, 40, "|.........|");
  mvprintw(15, 40, "-----------");*/

  rooms[2] = createRoom(40, 10, 6, 11);
  drawRoom(rooms[2]);

  return rooms;
}

Room * createRoom(int x, int y, int height, int width) {
  Room * newRoom;
  newRoom = malloc(sizeof(Room));

  newRoom->position.x = x;
  newRoom->position.y = y;
  newRoom->height = height;
  newRoom->width = width;

  return newRoom;
}

int drawRoom(Room * room) {
  int x;
  int y;

  /*draw top and bottom*/

  for (x = room->position.x; x < room->position.x + room->width; x++) 
  {
    mvprintw(room->position.y, x, "-"); /*top*/
    mvprintw(room->position.y + room->height - 1, x, "-");
  }
  
  /*draw floors and side walls*/

  for (y = room->position.y + 1; y < room->position.y + room->height - 1; y++)
  {
    /*draw side walls*/
    mvprintw(y, room->position.x, "|");
    mvprintw(y, room->position.x + room->width - 1, "|");

    /*draw floors*/
    for (x = room->position.x + 1; x < room->position.x + room->width - 1; x++) 
    {
      mvprintw(y, x, ".");
    }
    
  }
  

  return 1;
}

Player * playerSetUp() {
  Player * newPlayer;
  newPlayer = malloc(sizeof(Player));

  newPlayer->position.x = 14;
  newPlayer->position.y = 14;
  newPlayer->health = 20;

  mvprintw(newPlayer->position.y, newPlayer->position.x, "@");
  move(newPlayer->position.y, newPlayer->position.x);

  return newPlayer;
}

int handleInput(int input, Player * player) {
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

int checkPosition(int y, int x, Player * entity) {
  int space;
  switch (mvinch(y,x))
  {
  case '.':
    playerMove(y, x, entity);
    break;
  
  default:
    move(entity->position.y, entity->position.x);
    break;
  }
}

int playerMove(int y, int x, Player * player) {
  mvprintw(player->position.y, player->position.x, ".");
  
  player->position.y = y;
  player->position.x = x;

  mvprintw(player->position.y, player->position.x, "@");
  move(player->position.y, player->position.x);

  return 1;
}