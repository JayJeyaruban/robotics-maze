#include <stdbool.h>
/*
 * Sets initial dist values of the maze array and visited to false.
 */
void setupMaze();


/*
 * Returns an int value to indicate which direction to go:
 * 0 - west; 1 - north; 2 - east; 3 - south
 */
int findMinNeighbour(int x, int y);


/*
 * Takes input of x and y coordinates and bool values for n/e/s/w.
 * Updates the global maze array at point x and y and gives it the values in
 * the input node.
 */
 void visitPoint(int x, int y);

 void updateDir(int x, int y, int d, bool val);

/*
 * Updates the dist values in the maze array when a coordinate is updated.
 */
void updateMaze(int x, int y);

int getDist(int x, int y);

bool getVisited(int x, int y, int dir);
