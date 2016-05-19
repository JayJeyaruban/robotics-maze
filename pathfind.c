#include "pathfind.h"

/*
 * Returns an int value to indicate which direction to go:
 * 0 - west; 1 - north; 2 - east; 3 - south
 */
int findMinNeighbour(int x, int y) {
  int minDist = 255;
  int minDir = 5;
  int i;
  for (i=0; i<4; i++) {
    if (maze[x][y].dir[i] == true) {
      if (i == 0 && maze[x-1][y].dist < minDist) {
        minDist = maze[x-1][y].dist;
        minDir = i;
      } else if (i == 1 && maze[x][y+1].dist < minDist) {
        minDist = maze[x][y+1].dist;
        minDir = i;
      } else if (i == 2 && maze[x+1][y].dist < minDist) {
        minDist = maze[x+1][y].dist;
        minDir = i;
      } else {
        minDist = maze[x][y-1].dist;
        minDir = i;
      }
    }
  }
  return minDir;
}

void zeroRadTurn(int angle) {
  int ticks = angle*284/1000;
  drive_goto(ticks, -ticks);
}

void changeOrientation(int current, int new) {
  int diff = current - new;
  if (diff < 0)
    diff = -diff;
  if (diff == 2) {
    zeroRadTurn(180);
  } else if (diff) {
    switch (current) {
      case 0 :
        switch (new) {
          case 1 :
            zeroRadTurn(90);
            break;
          case 3 :
            zeroRadTurn(-90);
            break;
        }
        break;
      case 1 :
        switch (new) {
          case 0 :
            zeroRadTurn(-90);
            break;
          case 2 :
            zeroRadTurn(90);
            break;
        }
        break;
      case 2 :
        switch (new) {
          case 1 :
            zeroRadTurn(-90);
            break;
          case 2 :
            zeroRadTurn(90);
            break;
        }
        break;
      case 3 :
        switch (new) {
          case 0 :
            zeroRadTurn(90);
            break;
          case 2 :
            zeroRadTurn(-90);
            break;
        }
        break;
    }
  }
}

void pathFind() {

}
