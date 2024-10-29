#include "rogue.h"

int main()
{
  Player *player;
  int ch;
  Position *newPosition;

  Level *level;

  screenSetUp();

  level = createLevel(1);

  player = playerSetUp();

  while ((ch = tolower(getch())) != 'q')
  {
    newPosition = handleInput(ch, player);
    checkPosition(newPosition, player, level->tiles);
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
  noecho();
  refresh();

  srand(time(NULL));

  return 1;
}
