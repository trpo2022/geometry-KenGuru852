#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>
#include <libgeom/dlina_storony.h>
#include <libgeom/figures.h>
#include <libgeom/findnumber.h>
#include <libgeom/isdigit.h>
#include <libgeom/perimetr_tri.h>
#include <libgeom/triangle.h>
#include <math.h>
#include <string>
#include <vector>

#define M_PI 3.14159265358979323846
using namespace std;

triangle Triangle(string str, int& j) // Функция треугольника
{
    vector<string> nums;
    for (int i = 0; i < 8; i++) {
        string tmp = findnumber(str, j);
        if (!is_number(tmp, j))
            exit(1);
        nums.push_back(tmp);
        if ((unsigned long)j < str.size())
            j++;
    }
    vector<float> x;
    vector<float> y;
    int N = nums.size();
    for (int i = 0; i < N; i++) {
        if (i % 2)
            y.push_back(stof(nums[i]));
        else
            x.push_back(stof(nums[i]));
    }
    float a = Dlina_Storony(x[0], y[0], x[1], y[1]);
    float b = Dlina_Storony(x[1], y[1], x[2], y[2]);
    float c = Dlina_Storony(x[2], y[2], x[0], y[0]);
    float half_per = (Perimetr_Tri(a, b, c)) / 2;
    float perimetr_tri = Perimetr_Tri(a, b, c);
    float area_tri
            = sqrt(half_per * (half_per - a) * (half_per - b) * (half_per - c));
    return triangle(str, perimetr_tri, area_tri);

