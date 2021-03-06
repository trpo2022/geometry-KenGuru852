#include <libgeom/circle.h>
#include <libgeom/figures.h>
#include <libgeom/findnumber.h>
#include <libgeom/isdigit.h>
#include <math.h>
#include <vector>

using namespace std;
circle Circle(string str, int& j) // Функция круга. Вытаскиваем числа.
{
    vector<string> nums;
    for (int i = 0; i < 3; i++) {
        string tmp = findnumber(str, j);
        if (!is_number(tmp, j))
            exit(1);
        nums.push_back(tmp);
        if ((long unsigned)j < str.size())
            j++;
    }

    float rad_circle = stof(nums[2]);
    float perimetr_circle;
    perimetr_circle = M_PI * rad_circle * 2;
    float area_circle;
    area_circle = M_PI * pow(rad_circle, 2);
    Point center(stof(nums[0]), stof(nums[1]));
    return circle(center, str, perimetr_circle, area_circle, rad_circle);
}
