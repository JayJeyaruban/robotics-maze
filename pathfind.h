#ifndef PATHFIND_H
#define PATHFIND_H

#include "map.h"

/*
 * Returns an int value to indicate which direction to go:
 * 0 - west; 1 - north; 2 - east; 3 - south
 */
int findMinNeighbour(int x, int y);

/*
 * Uses zeroRadTurn function to change orientation of robot.
 * Takes an input of the currentOrientation and desiredOrientation of values
 * 0-3. Number to physical conversion:
 * 0 - west; 1 - north; 2 - east; 3 - south
 */
void changeOrientation(int currentOrientation, int desiredOrientation);

void pathfind();

#endif /* PATHFIND_H */
