#include "sensorread.h"
#include "simpletools.h"
#include "abdrive.h"

#define SPEED 80
#define DIFF 10
#define OPTIMAL 13
#define TOLERANCE 0
#define GO_TICKS 125

/*
 * Calculates the new direction for zeroRadTurn
 */
int newDir(int angle, int dir) {
  dir += angle;
  dir %=4;
  if (dir < 0) dir += 4;
  return dir;
}

/*
 * Turns the robot angle times 90 degrees and updates direction
 */
void zeroRadTurn(int angle, int *dir) {
  *dir = newDir(angle, *dir);
  if (*dir < 0) *dir += 4;
  int ticks = angle*90*292/1000;
  drive_goto(ticks, -ticks);
}

/*
 * Drives a fixed amount of ticks without bumping into walls
 * Also, updates x, y values
 */
void driveNavigate(int *x, int *y, int direction){
    int left, right;
    drive_getTicks(&left, &right);
    int leftStart = left;
    int speedL, speedR;
    int l,r;
    readSideValues(&l, &r);
    while(left-leftStart<= GO_TICKS && readFront() > 15){
      readSideValues(&l, &r);
      speedL = SPEED;
      speedR = SPEED;
      if(l<20){
        if(abs(l-OPTIMAL)>TOLERANCE) speedL -= abs(l-OPTIMAL)/(l-OPTIMAL)*DIFF;
      }else if (r<20){
        if(abs(r-OPTIMAL)>TOLERANCE) speedR -= abs(r-OPTIMAL)/(r-OPTIMAL)*DIFF;
      }
      drive_speed(speedL, speedR);
      drive_getTicks(&left, &right);
    }
    switch(direction){
      case 1: *y += 1; break;
      case 2: *x += 1; break;
      case 3: *y -= 1; break;
      case 0: *x -= 1; break;
    }
    drive_speed(0, 0);
}
