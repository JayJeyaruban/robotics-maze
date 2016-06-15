
#include "sensorread.h"
#include "simpletools.h"
#include "abdrive.h"
#include "drive.h"
#include <stdbool.h>
#include "map.h"

int x = 0;
int y = -1;
int direction = 1;

void explore(){
  // GO FORWARD
  driveNavigate(&x, &y, direction);

  if(x!=0||y!=0) updateDir(x, y, ((direction+2)%4), false);

  visitPoint(x, y);
  //EXPLORE FURTHER

  bool temp;
  int i;
  zeroRadTurn(-1, &direction);

  for (i = 0; i < 3; i++){
    temp = readFront()<30;
    updateDir(x, y, direction, temp);
    if(!temp && !getVisited(x, y, direction)) explore();
    zeroRadTurn(1, &direction);
  }

  updateMaze(x,y);


  //RETURN
  driveNavigate(&x, &y, direction);
  zeroRadTurn(-2, &direction);
}
