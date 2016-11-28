#include <stdio.h>
#include <math.h>
#include <Windows.h>

//#include <math.h>
//#include <time.h>
//#include <stdlib.h>
#include <random>
//#include <algorithm>

double gaussianRandom(double average, double stdev) {
  double v1, v2, s, temp;

  do {
    v1 =  2 * ((double) rand() / RAND_MAX) - 1;      // -1.0 ~ 1.0 까지의 값
    v2 =  2 * ((double) rand() / RAND_MAX) - 1;      // -1.0 ~ 1.0 까지의 값
    s = v1 * v1 + v2 * v2;
  } while (s >= 1 || s == 0);

  s = sqrt( (-2 * log(s)) / s );

  temp = v1 * s;
  temp = (stdev * temp) + average;

  return temp;
}

void main() {
	printf("%lf \n",gaussianRandom(0.0, 1.0));
}