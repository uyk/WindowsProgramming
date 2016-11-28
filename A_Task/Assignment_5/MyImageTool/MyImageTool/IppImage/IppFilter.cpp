#include "stdafx.h"
#include "IppFilter.h"

#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <random>
#include <algorithm>

#include <stdio.h>
#include <math.h>
#include <Windows.h>


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

void IppNoiseGaussian(IppByteImage& imgSrc, IppByteImage& imgDst, int amount)
{
	int size = imgSrc.GetSize();

	imgDst = imgSrc;
	BYTE* pDst = imgDst.GetPixels();

	unsigned int seed = static_cast<unsigned int>(time(NULL));
	//std::default_random_engine generator(seed);
	//std::normal_distribution<double> distribution(0.0, 1.0);
	//gaussianRandom(0.0, 1.0);	//평균이 0이고 표준편차가 1인 가우시안 난수 발생

	double rn;
	for (int i = 0; i < size; i++)
	{
		//rn = distribution(generator) * 255 * amount / 100;
		rn = gaussianRandom(0.0, 1.0) * 255 * amount / 100;
		pDst[i] = static_cast<BYTE>(limit(pDst[i] + rn));
	}
}

void IppNoiseSaltNPepper(IppByteImage& imgSrc, IppByteImage& imgDst, int amount)
{
	int size = imgSrc.GetSize();

	imgDst = imgSrc;
	BYTE* pDst = imgDst.GetPixels();

	unsigned int seed = static_cast<unsigned int>(time(NULL));
	//std::default_random_engine generator(seed);
	//std::uniform_int_distribution<int> distribution(0, size - 1);
	int rn;

	int num = size * amount / 100;

	for (int i = 0; i < num; i++)
	{
		//pDst[distribution(generator)] = (i & 0x01) * 255;
		rn = (int)gaussianRandom(0.0, size - 1);

		//while (rn < 0 && rn > size) {
		//	rn = (int)gaussianRandom(0.0, size - 1);
		//}
		if (rn >= 0 && rn < size)
			pDst[rn] = (i & 0x01) * 255;
	}
}