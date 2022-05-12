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

CTEST(Perimetr_Tri, test_true1)
{
    CTEST_LOG("Checking Perimetr_Tri() true function");
    const float expected = 10;
    float a = 2.5;
    float b = 3.5;
    float c = 4;
    float result = Perimetr_Tri(a, b, c);
    ASSERT_DBL_NEAR(expected, result);
}
CTEST(Perimetr_Tri, test_true2)
{
    CTEST_LOG("Checking Perimetr_Tri() true function");
    const float expected = 12.5;
    float a = 2.5;
    float b = 3.5;
    float c = 6.5;
    float result = Perimetr_Tri(a, b, c);
    ASSERT_DBL_NEAR(expected, result);
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
CTEST(Dlina_Storony, dlina_true1)
{
    CTEST_LOG("Checking Dlina_Storony() on true");
    float x1 = 2.5;
    float y1 = 3.5;
    float x2 = 6.5;
    float y2 = 0.5;
    float expected = 5;
    float result = Dlina_Storony(x1, y1, x2, y2);
    ASSERT_DBL_NEAR(expected, result);
}
CTEST(Dlina_Storony, dlina_true2)
{
    CTEST_LOG("Checking Dlina_Storony() on true");
    float x1 = 5;
    float y1 = 7;
    float x2 = 13;
    float y2 = 1;
    float expected = 10;
    float result = Dlina_Storony(x1, y1, x2, y2);
    ASSERT_DBL_NEAR(expected, result);
}
CTEST(Circle, check_area_true1)
{
    CTEST_LOG("Checking Circle() on area true");
    circle test;
    std::string testing = "circle(0 0, 1.5)";
    int j = 7;
    test = Circle(testing, j);
    float result = test.area;
    float expected = 7.06858;
    ASSERT_DBL_NEAR(expected, result);
}
CTEST(Circle, check_area_true2)
{
    CTEST_LOG("Checking Circle() on area true");
    circle test;
    std::string testing = "circle(7 9, 4.13)";
    int j = 7;
    test = Circle(testing, j);
    float result = test.area;
    float expected = 53.5858;
    ASSERT_DBL_NEAR(expected, result);
}
CTEST(Circle, check_per_true1)
{
    CTEST_LOG("Checking Circle() on perimetr true");
    circle test;
    std::string testing = "circle(0 0, 1.5)";
    int j = 7;
    test = Circle(testing, j);
    float result = test.per;
    float expected = 9.42478;
    ASSERT_DBL_NEAR(expected, result);
}
CTEST(Circle, check_per_true2)
{
    CTEST_LOG("Checking Circle() on perimetr true");
    circle test;
    std::string testing = "circle(7 9, 4.13)";
    int j = 7;
    test = Circle(testing, j);
    float result = test.per;
    float expected = 25.9496;
    ASSERT_DBL_NEAR(expected, result);
}
CTEST(Circle, check_rad_true1)
{
    CTEST_LOG("Checking Circle() on radius true");
    circle test;
    std::string testing = "circle(0 0, 1.5)";
    int j = 7;
    test = Circle(testing, j);
    float result = test.rad;
    float expected = 1.5;
    ASSERT_DBL_NEAR(expected, result);
}
CTEST(Circle, check_rad_true2)
{
    CTEST_LOG("Checking Circle() on radius true");
    circle test;
    std::string testing = "circle(7 9, 4.13)";
    int j = 7;
    test = Circle(testing, j);
    float result = test.rad;
    float expected = 4.13;
    ASSERT_DBL_NEAR(expected, result);
}
CTEST(Circle, check_string_true1)
{
    CTEST_LOG("Checking Circle() on string true");
    circle test;
    std::string testing = "circle(0 0, 1.5)";
    int j = 7;
    test = Circle(testing, j);
    std::string expected = "circle(0 0, 1.5)";
    std::string result = test.func_name;
    ASSERT_STR(expected.c_str(), result.c_str());
}
CTEST(Circle, check_string_true2)
{
    CTEST_LOG("Checking Circle() on string true");
    circle test;
    std::string testing = "circle(7 9, 4.13)";
    int j = 7;
    test = Circle(testing, j);
    std::string expected = "circle(7 9, 4.13)";
    std::string result = test.func_name;
    ASSERT_STR(expected.c_str(), result.c_str());
}
CTEST(circle_point, check_point_true1)
{
    CTEST_LOG("Checking on point true");
    circle test;
    std::string testing = "circle(0 0, 1.5)";
    int j = 7;
    test = Circle(testing, j);
    Point result = test.center;
    Point expected(0, 0);
    ASSERT_DBL_NEAR(expected.x, result.x);
    ASSERT_DBL_NEAR(expected.y, result.y);
}
CTEST(circle_point, check_point_true2)
{
    CTEST_LOG("Checking on point true");
    circle test;
    std::string testing = "circle(7 9, 4.13)";
    int j = 7;
    test = Circle(testing, j);
    Point result = test.center;
    Point expected(7, 9);
    ASSERT_DBL_NEAR(expected.x, result.x);
    ASSERT_DBL_NEAR(expected.y, result.y);
}
CTEST(findnumber, check_true1)
{
    CTEST_LOG("Checking on findnumber_true");
    std::string testing = "circle(8 0, 1.5)";
    int j = 7;
    std::string expected = "8";
    std::string result = findnumber(testing, j);
    ASSERT_STR(expected.c_str(), result.c_str());
}
CTEST(findnumber, check_true2)
{
    CTEST_LOG("Checking on findnumber_true");
    std::string testing = "circle(7 9, 1.5)";
    int j = 7;
    std::string expected = "7";
    std::string result = findnumber(testing, j);
    ASSERT_STR(expected.c_str(), result.c_str());
}

CTEST(intersections, check_true)
{
    CTEST_LOG("Checking on intersections_true");
    std::vector<circle> arr;
    std::string circle1 = "circle(-2 0, 1)";
    std::string circle2 = "circle(0 0, 2)";
    std::string circle3 = "circle(2 0, 1)";
    int j = 7;
    arr.push_back(Circle(circle1, j));
    j = 7;
    arr.push_back(Circle(circle2, j));
    j = 7;
    arr.push_back(Circle(circle3, j));
    bool real = findIntersections(arr);
    ASSERT_TRUE(real);
}

CTEST(intersections, check_false)
{
    CTEST_LOG("Checking on intersections_false");
    std::vector<circle> arr;
    std::string circle1 = "circle(-7 0, 1)";
    std::string circle2 = "circle(0 0, 2)";
    std::string circle3 = "circle(7 0, 1)";
    int j = 7;
    arr.push_back(Circle(circle1, j));
    j = 7;
    arr.push_back(Circle(circle2, j));
    j = 7;
    arr.push_back(Circle(circle3, j));
    bool real = findIntersections(arr);
    ASSERT_FALSE(real);
}
CTEST(isdigit, check_true)
{
    CTEST_LOG("Checking is_number() on isdigit_true");
    std::string testing = "0";
    int j = 0;
    bool result = is_number(testing, j);
    ASSERT_TRUE(result);
}
CTEST(isdigit, check_false)
{
    CTEST_LOG("Checking is_number() on isdigit_false");
    std::string testing = "asdf";
    int j = 0;
    bool result = is_number(testing, j);
    ASSERT_FALSE(result);
}
CTEST(Triangle, check_str_true1)
{
    CTEST_LOG("Checking Triangle() on str_true");
    triangle test;
    std::string testing = "triangle((3 -2, 3 2, 1 0, 3 -2))";
    int j = 10;
    test = Triangle(testing, j);
    std::string expected = "triangle((3 -2, 3 2, 1 0, 3 -2))";
    std::string result = test.func_name;
    ASSERT_STR(expected.c_str(), result.c_str());
}
CTEST(Triangle, check_str_true2)
{
    CTEST_LOG("Checking Triangle() on str_false");
    triangle test;
    std::string testing = "triangle((-5.0 -2, -1 0.0, -3.0 2.0, -3 -2))";
    int j = 10;
    test = Triangle(testing, j);
    std::string expected = "triangle((-5.0 -2, -1 0.0, -3.0 2.0, -3 -2))";
    std::string result = test.func_name;
    ASSERT_STR(expected.c_str(), result.c_str());
}
CTEST(Triangle, check_area_true1)
{
    CTEST_LOG("Checking Triangle() on area true");
    triangle test;
    std::string testing = "triangle((3 -2, 3 2, 1 0, 3 -2))";
    int j = 10;
    test = Triangle(testing, j);
    float result = test.area;
    float expected = 4;
    ASSERT_DBL_NEAR(expected, result);
}
CTEST(Triangle, check_area_true2)
{
    CTEST_LOG("Checking Triangle() on area false");
    triangle test;
    std::string testing = "triangle((-5.0 -2, -1 0.0, -3.0 2.0, -3 -2))";
    int j = 10;
    test = Triangle(testing, j);
    float result = test.area;
    float expected = 6;
    ASSERT_DBL_NEAR(expected, result);
}
