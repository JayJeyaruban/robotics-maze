
/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials
*/
#include "simpletools.h"                      // Include simple tools
#include <stdbool.h>
#include "map.h"

bool visited[4][4];
bool dir[4][4][4];
int dist[4][4];
/*
 * Sets initial dist values of the maze array and visited to false.
 */
void setupMaze() {
  int i;
  for (i=0; i<4; i++) {
    int j;
    for (j=0; j<4; j++) {
      dist[i][j] = 255;
      visited[i][j] = false;
      int k;
      for(k=0;k<4;k++){
        dir[i][j][k] = true;
      }
    }
  }
  dist[3][3] = 0;
}

/*
 * Returns an int value to indicate which direction to go:
 * 0 - west; 1 - north; 2 - east; 3 - south
 */
int findMinNeighbour(int x, int y) {
  int minDist = 255;
  int minDir = 5;
  if(!dir[x][y][0]){
    if(dist[x-1][y] < minDist){
      minDist =  dist[x-1][y];
      minDir = 0;
    }
  }
  if(!dir[x][y][1]){
    if(dist[x][y+1] < minDist){
      minDist =  dist[x][y+1];
      minDir = 1;
    }
  }
  if(!dir[x][y][2]){
    if(dist[x+1][y] < minDist){
      minDist =  dist[x+1][y];
      minDir = 2;
    }
  }
  if(!dir[x][y][3]){
    if(dist[x][y-1] < minDist){
      minDist =  dist[x][y-1];
      minDir = 3;
    }
  }
  return minDir;
}


/*
 * Updates node at x, y in the maze array with bool for n/e/s/w walls.
 * Then calls updateMaze to update the dist values of the current and adjacent
 * nodes.
 */
void visitPoint(int x, int y){
  visited[x][y] = true;
}

void updateDir(int x, int y, int d, bool val){
  dir[x][y][d] = val;
}

/*
 * Updates the dist value at the input x, y position as well as adjacent nodes
 * with a possible path.
 */
void updateMaze(int x, int y) {
  int minDist = 255;

  if(!dir[x][y][0]){
    if(dist[x-1][y] < minDist) minDist =  dist[x-1][y];
  }
  if(!dir[x][y][1]){
    if(dist[x][y+1] < minDist) minDist =  dist[x][y+1];
  }
  if(!dir[x][y][2]){
    if(dist[x+1][y] < minDist) minDist =  dist[x+1][y];
  }
  if(!dir[x][y][3]){
    if(dist[x][y-1] < minDist) minDist =  dist[x][y-1];
  }

  if(dist[x][y] != 0 && dist[x][y] != minDist + 1){
    dist[x][y] = minDist + 1;
    if(!dir[x][y][0]) updateMaze(x-1, y);
    if(!dir[x][y][1]) updateMaze(x, y+1);
    if(!dir[x][y][2]) updateMaze(x+1, y);
    if(!dir[x][y][3]) updateMaze(x, y-1);
  }
}

/*
 * Returns the distance at a point
 */

int getDist(int x, int y) {
  return dist[x][y];
}

/*
 * Returns whether or not the point was visited and true if it does not exist
 */

bool getVisited(int x, int y, int dir) {
  switch(dir){
      case 1: y++; break;
      case 2: x++; break;
      case 3: y--; break;
      case 0: x--; break;
    }

  if(x>=0&&x<4&&y<4&&y>=0) return visited[x][y];
  return true;
}
