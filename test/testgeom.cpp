#include <cctype>
#include <cstring>
#include <ctest.h>
#include <fstream>
#include <iostream>
#include <libgeom/check.h>
#include <libgeom/circle.h>
#include <libgeom/dlina_storony.h>
#include <libgeom/figures.h>
#include <libgeom/findnumber.h>
#include <libgeom/intersections.h>
#include <libgeom/isdigit.h>
#include <libgeom/perimetr_tri.h>
#include <libgeom/print_circle.h>
#include <libgeom/print_tri.h>
#include <libgeom/triangle.h>
#include <math.h>
#include <string>
#include <vector>

#define M_PI 3.14159265358979323846

CTEST(perimetr_tri, test_true)
{
    CTEST_LOG("Checking Perimetr_Tri() function ");
    const int expected = 10;
    float a = 2.5;
    float b = 3.5;
    float c = 4;
    float result = Perimetr_Tri(a, b, c);
    bool real = (result == expected);
    ASSERT_TRUE(real);
}
