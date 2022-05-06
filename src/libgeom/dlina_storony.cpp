#include "libgeom/dlina_storony.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <cctype>
#include <string>
#include <math.h> 

#define M_PI 3.14159265358979323846


float Dlina_Storony (float x1, float y1, float x2, float y2)
{
	float dlina_storony;
	dlina_storony = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
	return dlina_storony;
}

