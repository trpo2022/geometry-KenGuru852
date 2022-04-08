#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <cctype>
#include <string>
#include <math.h> 

#define M_PI 3.14159265358979323846

using namespace std;
float area_circle;
float perimetr_circle;
float area_tri;
float perimetr_tri;

struct circle
{
	string func_name;
	float per;
	float area;
	circle() {};
	circle(string _func_name, float _per, float _area): func_name(_func_name), per(_per), area(_area) {};
};

struct triangle
{
	string func_name;
	float per;
	float area;
	triangle() {};
	triangle(string _func_name, float _per, float _area): func_name(_func_name), per(_per), area(_area) {};
};

string tr = "triangle", ci = "circle";

bool check_function(string f) // Вывод ошибки в названии фигуры
{
	if(f == ci || f == tr) return true;
	else
	{
		cout << "Error at column 0: expected 'circle' or 'triangle'";
		return false;
	}
}

bool is_number(string n, int j) // Ошибка, если что-то другое вместо цифры
{
	for(int i=0;i<n.size();i++)
	{
		if(!isdigit(n[i]) && n[i] != '-' && n[i]!='.')
		{
			cout << "Error at column " << j-(n.size()-i-1) <<": expected '<double>'";
			return false;
		}
	}
	return true;
}

string findnumber(string str, int &j) // Ищем числа в строке
{
	string num = "";
	while(str[j] != ' ' && str[j] != ',' && str[j] != ')') //проверка на цифры
	{
		num += str[j];
		j++;
		if(j >= str.size()) break;
	}
	if(str[j] == ',' && j < str.size()) j++;
	return num;
}

float Perimetr_Tri (float a, float b, float c)
{
	return a+b+c;
}

float Dlina_Storony (float x1, float y1, float x2, float y2)
{
	float dlina_storony;
	dlina_storony = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
	return dlina_storony;
}

circle Circle(string str, int &j) // Функция круга. Вытаскиваем числа.
{
	vector<string> nums;
	for(int i = 0; i<3;i++)
	{
		string tmp = findnumber(str,j);
		if(!is_number(tmp, j)) exit(1); 
		nums.push_back(tmp);
		if(j < str.size()) j++;
	}

	float x_circle = stof(nums[0]);
	float y_circle = stof(nums[1]);
	float rad_circle = stof(nums[2]);
	float perimetr_circle;
	perimetr_circle = M_PI * rad_circle * 2;
	float area_circle;
	area_circle = M_PI * pow(rad_circle, 2);
	return circle(str,perimetr_circle,area_circle);
}

triangle Triangle(string str, int &j) // Функция треугольника
{
	vector<string> nums;
	for(int i = 0; i<8;i++)
	{
		string tmp = findnumber(str,j);
		if(!is_number(tmp, j)) exit(1); 
		nums.push_back(tmp);
		if(j < str.size()) j++;
	}
	vector<float> x;
	vector<float> y;
	for(int i=0;i<nums.size();i++)
	{
		if(i%2) y.push_back(stof(nums[i]));
		else x.push_back(stof(nums[i]));
	}
	float a = Dlina_Storony (x[0], y[0], x[1], y[1]);
	float b = Dlina_Storony (x[1], y[1], x[2], y[2]);
	float c = Dlina_Storony (x[2], y[2], x[0], y[0]);
	float half_per = (Perimetr_Tri (a, b, c)) / 2;
	perimetr_tri = Perimetr_Tri (a, b, c);
	area_tri = sqrt(half_per*(half_per - a)*(half_per-b)*(half_per-c));
	return triangle(str, perimetr_tri, area_tri);
}

void print_circle(circle c, int i)
{
	cout << i + 1 << ". " <<c.func_name << endl;
	cout <<"\t perimetr = " << c.per << endl;
	cout <<"\t area = " << c.area << endl;
}

void print_tri(triangle c, int i)
{
	cout << i + 1 << ". " << c.func_name << endl;
	cout <<"\t perimetr = " << c.per << endl;
	cout <<"\t area = " << c.area << endl;
}

int main() //����
{
	ifstream fin("input.txt");
	vector<string> str;
	while(!fin.eof())
	{
		string tmp; // Считываем строку
		getline(fin,tmp); //Считываем до первого пробела
		str.push_back(tmp); //Значение строку в файл
	}
	fin.close();
	for(int i=0;i<str.size();i++)
	{
		while (str[i].find("  ", 0) != -1)
        {
            str[i].replace(str[i].find("  ", 0), 2, " ");
        }
		cout << str[i] << endl; //Вывод строки
	}
	circle c;
	triangle tri;
	for(int i=0; i<str.size();i++)
	{
		int j = 0, bal = 0;
		string func = "";
		while(str[i][j] != '(' && str[i][j] != ')') // Проверка названия фигуры + регистр
		{
			func += tolower(str[i][j]);
			j++;
			if(j >= str[i].size()) break;
		}
		if(str[i][j] == '(') bal++;
		if(!check_function(func)) break;
		if(str[i][j] == ')') // Проверка на первую скобку(
		{
			cout << "Error at column " << j+1 <<": expected '('";
			break;
		}
		if(j < str[i].size()) j++;
		else break;
		if(str[i][j] == '(') bal++;
		if(func == tr && str[i][j] != '(') //Проверка на вторую скобку, если треугольник
		{
			cout << "Error at column " << j+1 <<": expected '('";
			break;			
		}
		//Цифры
		if(func == ci) c = Circle(str[i],j);
		if(func == tr) 
		{
			if(j < str[i].size()) j++;
			tri = Triangle(str[i],j);
		}
		while(str[i][j] == ')')
		{
			if(str[i][j] == ')' && bal > 0) bal--;
			j++;
		}
		if(++j < str[i].size())
		{
			cout << "\nError at column " << j+1 <<": unexpected token";
		}
		if(func == ci) print_circle(c,i);
		if(func == tr) print_tri(tri,i);
	}
	return 0;
}
