#include "drive.h"
#include "pathfind.h"
#include "map.h"

/*
 * Finds an optimal path to the finish line
 */
void pathFind() {
  int position = 6;
	int x = 0;
	int y = -1;
	int current = 1;
	driveNavigate(&x, &y, current);
	int new;
	while (position != 0) {
		new = findMinNeighbour(x, y);
    int change = new - current;
		if(change != 0) zeroRadTurn (change, &current);
		driveNavigate(&x, &y, current);
		position = getDist(x, y);
	}
}
