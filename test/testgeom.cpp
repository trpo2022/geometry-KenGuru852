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


CTEST(Perimetr_Tri, test_true)
{
    CTEST_LOG("Checking Perimetr_Tri() true function");
    const int expected = 10;
    float a = 2.5;
    float b = 3.5;
    float c = 4;
    float result = Perimetr_Tri(a, b, c);
    bool real = (result == expected);
    ASSERT_TRUE(real);
}
CTEST(Perimetr_Tri, test_false)
{
    CTEST_LOG("Checking Perimetr_Tri() false function");
    const int expected = 11;
    float a = 2.5;
    float b = 3.5;
    float c = 4;
    float result = Perimetr_Tri(a, b, c);
    bool real = (result == expected);
    ASSERT_FALSE(real);
}
CTEST(check_function, circle_true)
{
    CTEST_LOG("Checking check_function() on circle true");
    bool real = check_function("circle");
    ASSERT_TRUE(real);
}
CTEST(check_function, circle_false)
{
    CTEST_LOG("Checking check_function() on circle false");
    bool real = check_function("ciwpoghrcle");
    ASSERT_FALSE(real);
}
CTEST(check_function, triangle_true)
{
    CTEST_LOG("Checking check_function() on triangle true");
    bool real = check_function("triangle");
    ASSERT_TRUE(real);
}
CTEST(check_function, triangle_false)
{
    CTEST_LOG("Checking check_function() on triangle false");
    bool real = check_function("triangleajkghesjkhdskjgh");
    ASSERT_FALSE(real);
}
CTEST(Dlina_Storony, dlina_true)
{
    CTEST_LOG("Checking Dlina_Storony() on true");
    float x1 = 2.5;
    float y1 = 3.5;
    float x2 = 6.5;
    float y2 = 0.5;
    float expected = 5;
    float result = Dlina_Storony(x1, y1, x2, y2);
    bool real = (expected == result);
    ASSERT_TRUE(real);
}
CTEST(Dlina_Storony, dlina_false)
{
    CTEST_LOG("Checking Dlina_Storony() on false");
    float x1 = 2.5;
    float y1 = 3.5;
    float x2 = 6.5;
    float y2 = 0.5;
    float expected = 6;
    float result = Dlina_Storony(x1, y1, x2, y2);
    bool real = (expected == result);
    ASSERT_FALSE(real);
}
