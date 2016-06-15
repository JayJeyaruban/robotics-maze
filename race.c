#include "simpletools.h"
#include "explore.h"
#include "map.h"
#include "pathfind.h"

void blinkLED() {
  int i;
  for (i=0; i<3; i++) {
    low(26);
    pause(500);
    high(26);
    pause(500);
  }    
}

int main(void)
{
  setupMaze();
  pause(2000);
  explore();
  blinkLED();
  pause(1000);
  pathFind();
  return 0;
}
