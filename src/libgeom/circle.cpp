#include <libgeom/circle.h>
#include <libgeom/figures.h>
#include <libgeom/findnumber.h>
#include <libgeom/isdigit.h>
#include <math.h>
#include <vector>

#define M_PI 3.14159265358979323846
using namespace std;
circle Circle(string str, int &j) // Функция круга. Вытаскиваем числа.
{
	vector<string> nums;
	for(int i = 0; i<3;i++)
	{
		string tmp = findnumber(str,j);
		if(!is_number(tmp, j)) exit(1); 
		nums.push_back(tmp);
		if((long unsigned)j < str.size()) j++;
	}

	float rad_circle = stof(nums[2]);
	float perimetr_circle;
	perimetr_circle = M_PI * rad_circle * 2;
	float area_circle;
	area_circle = M_PI * pow(rad_circle, 2);
	return circle(str,perimetr_circle,area_circle);
}

