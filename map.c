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
  int currentDist = maze[x][y].dist
  int minDist = 255;
  
  int i;
  for (i=0; i<4; i++) {
    if (maze[x][y].dir[i]) {
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

  if (currentDist == minDist + 1) {

  } else {
    currentDist = minDist + 1;

  }


}

int getDist(int x, int y) {
  return maze[x][y].dist;
}
