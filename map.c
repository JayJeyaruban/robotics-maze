/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials
*/
#include "simpletools.h"                      // Include simple tools
#include <stdbool.h>
#include "map.h"

/*
 * Sets initial dist values of the maze array and visited to false.
 */
void setupMaze() {
  int i;
  for (i=0; i<4; i++) {
    int j;
    for (j=0; j<4; j++) {
      maze[i][j].dist = (3 - i) + (3 - j);
      maze[i][j].visited = false;
    }
  }
}

/*
 * Updates node at x, y in the maze array with bool for n/e/s/w walls.
 * Then calls updateMaze to update the dist values of the current and adjacent
 * nodes.
 */
void updatePoint(int x, int y, bool north, bool east, bool south, bool west) {
  maze[x][y].dir[0] = west;
  maze[x][y].dir[1] = north;
  maze[x][y].dir[2] = east;
  maze[x][y].dir[3] = south;

  updateMaze(x, y);
}

/*
 * Updates the dist value at the input x, y position as well as adjacent nodes
 * with a possible path.
 */
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
