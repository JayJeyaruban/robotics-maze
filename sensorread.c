#include "ping.h"
#include "simpletools.h"

#define PING 8
#define FREQ 38000
#define LEFT_PIN 11
#define RIGHT_PIN 1

/*
 * Returns the clear distance infront in cm
 */
int readFront() {
	return ping_cm(PING);
}

/*
 * Updates values of inputted left and right variables with the distances
 */
void readSideValues(int *left, int* right) {
	int dacVal;
  *left = 0;
  *right = 0;
	for (dacVal = 0; dacVal < 160; dacVal += 8) {
		dac_ctr(26,0,dacVal);
		freqout(LEFT_PIN,1,FREQ);
		*left += input(10);

		dac_ctr(27,1,dacVal);
		freqout(RIGHT_PIN,1,FREQ);
		*right += input(2);
	}
}
