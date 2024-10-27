#include "rogue.h"

int main()
{
  Player *player;
  int ch;
  Position *newPosition;

  char **level;

  screenSetUp();

  mapSetUp();

  level = saveLevelPositions();

  player = playerSetUp();

  while ((ch = tolower(getch())) != 'q')
  {
    handleInput(ch, player);
  }

  return 0;
}

int screenSetUp()
{
  if (initscr() == NULL)
  {
    fprintf(stderr, "Error inicializando la pantalla\n");
    exit(1);
  }
  printw("Hello world!");
  noecho();
  refresh();

  srand(time(NULL));

  return 1;
}
