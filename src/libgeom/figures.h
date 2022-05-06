#pragma once
#include <string>

struct circle
{
	std::string func_name;
	float per;
	float area;
	circle() {};
	circle(std::string _func_name, float _per, float _area): func_name(_func_name), per(_per), area(_area) {};
};

struct triangle
{
	std::string func_name;
	float per;
	float area;
	triangle() {};
	triangle(std::string _func_name, float _per, float _area): func_name(_func_name), per(_per), area(_area) {};
};
