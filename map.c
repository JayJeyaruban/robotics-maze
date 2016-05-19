/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials
*/
#include "simpletools.h"                      // Include simple tools
#include <stdbool.h>
#include "map.h"


// Currently takes a node pointer as input, can be changed to n/e/s/w for node.
void updatePoint(int x, int y, bool north, bool east, bool south, bool west) {
  maze[x][y].dir[0] = west;
  maze[x][y].dir[1] = north;
  maze[x][y].dir[2] = east;
  maze[x][y].dir[3] = south;

  updateMaze(x, y);
}

void updateMaze(int x, int y) {
  int minDist = 255;

  int i;
  for (i=0; i<4; i++) {
    if (maze[x][y].dir[i] == true) {
      if (i == 0 && maze[x-1][y].dist < minDist) {
        minDist = maze[x-1][y].dist;
      } else if (i == 1 && maze[x][y+1].dist < minDist) {
        minDist = maze[x][y+1].dist;
      } else if (i == 2 && maze[x+1][y].dist < minDist) {
        minDist = maze[x+1][y].dist;
      } else {
        minDist = maze[x][y-1].dist;
      }
    }
  }

  if (maze[x][y].dist != minDist + 1) {
    maze[x][y].dist = minDist + 1;
    int j;
    for (j=0; j<4; j++) {
      if (maze[x][y].dir[j] == true) {
        if (j == 0) {
          updateMaze(x-1,y);
        } else if (j == 1) {
          updateMaze(x,y+1);
        } else if (j == 2) {
          updateMaze(x+1,y);
        } else {
          updateMaze(x,y-1);
        }
      }
    }
  }

}

int getDist(int x, int y) {
  return maze[x][y].dist;
}
