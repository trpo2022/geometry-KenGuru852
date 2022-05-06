#include <libgeom/findnumber.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <cctype>
#include <string>
#include <math.h> 

#define M_PI 3.14159265358979323846

std::string findnumber(std::string str, int &j) // Ищем числа в строке
{
	std::string num = "";
	int N = str.size();
	while(str[j] != ' ' && str[j] != ',' && str[j] != ')') //проверка на цифры
	{
		num += str[j];
		j++;
		if(j >= N) break;
	}
	if(str[j] == ',' && j < N) j++;
	return num;
}
