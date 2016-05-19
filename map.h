#ifndef MAP_H
#define MAP_H

// Default for dist needs to be set to 255 and visited = false
typedef struct node {
  bool dir[4];
  int dist;
  bool visited;
} Node;

Node maze[4][4];

/*
 * Sets initial dist values of the maze array and visited to false.
 */
void setupMaze();

/*
 * Takes input of x and y coordinates and bool values for n/e/s/w.
 * Updates the global maze array at point x and y and gives it the values in
 * the input node.
 */
void updatePoint(int x, int y, bool north, bool east, bool south, bool west);

/*
 * Updates the dist values in the maze array when a coordinate is updated.
 */
void updateMaze(int x, int y);

int getDist(int x, int y);

#endif /* MAP_H */
