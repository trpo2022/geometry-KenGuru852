#include "libgeom/dlina_storony.h"

#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

float Dlina_Storony(float x1, float y1, float x2, float y2)
{
    float dlina_storony;
    dlina_storony = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    return dlina_storony;
}

