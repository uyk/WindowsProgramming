#pragma once;
#include "IppImage.h"
#include "IppDib.h"

double gaussianRandom(double average, double stdev);
void IppNoiseGaussian(IppByteImage& imgSrc, IppByteImage& imgDst, int amount);
void IppNoiseSaltNPepper(IppByteImage& imgSrc, IppByteImage& imgDst, int amount);