#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <cctype>

using namespace std;

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

string findnumber(string str, int &j) // ищем число в строке
{
	string num = "";
	while(str[j] != ' ' && str[j] != ',' && str[j] != ')') //проверка цифр
	{
		num += str[j];
		j++;
		if(j >= str.size()) break;
	}
	return num;
}

void Circle(string str, int &j) // рассчет круга
{
	string num1 = findnumber(str, j);
	if(!is_number(num1, j)) return;
	if(j < str.size()) j++;
	else return;
	string num2 = findnumber(str, j);
	if(!is_number(num2, j)) return;
	if(j+2 < str.size()) j+=2;
	else return;
	string num3 = findnumber(str,j);
	if(!is_number(num3, j)) return;
	cout << num1 << " " << num2 << " " << num3;
}

void Triangle(string str, int &j) // рассчет треугольника
{
	return;
}

int main() //база
{
	ifstream fin("input.txt");
	vector<string> str;
	while(!fin.eof())
	{
		string tmp; // временная переменная, куда считываем строку
		getline(fin,tmp); //считывать до первого пробела
		str.push_back(tmp); //значение строки в файл
	}
	fin.close();
	for(int i=0;i<str.size();i++)
	{
		while (str[i].find("  ", 0) != -1)
        {
            str[i].replace(str[i].find("  ", 0), 2, " ");
        }
		cout << str[i] << endl; //вывод строк
	}
	for(int i=0; i<str.size();i++)
	{
		int j = 0, bal = 0;
		string func = "";
		while(str[i][j] != '(' && str[i][j] != ')') //проверка названия функции + регистр
		{
			func += tolower(str[i][j]);
			j++;
			if(j >= str[i].size()) break;
		}
		if(str[i][j] == '(') bal++;
		if(!check_function(func)) break;
		if(str[i][j] == ')') // проверка на первую скобку (
		{
			cout << "Error at column " << j+1 <<": expected '('";
			break;
		}
		if(j < str[i].size()) j++;
		else break;
		if(str[i][j] == '(') bal++;
		if(func == tr && str[i][j] != '(') //проверка на вторую строку, если треугольник
		{
			cout << "Error at column " << j+1 <<": expected '('";
			break;			
		}
		// проверка циферий
		if(func == ci) Circle(str[i],j);
		if(func == tr) Triangle(str[i],j);
		while(str[i][j] == ')')
		{
			if(str[i][j] == ')' && bal > 0) bal--;
			j++;
		}
		if(++j < str[i].size())
		{
			cout << "\nError at column " << j+1 <<": unexpected token";
		}
		break;
	}
	return 0;
}
