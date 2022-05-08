#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>
#include <libgeom/check.h>
#include <libgeom/circle.h>
#include <libgeom/dlina_storony.h>
#include <libgeom/figures.h>
#include <libgeom/findnumber.h>
#include <libgeom/isdigit.h>
#include <libgeom/perimetr_tri.h>
#include <libgeom/print_circle.h>
#include <libgeom/print_tri.h>
#include <libgeom/triangle.h>
#include <math.h>
#include <string>
#include <vector>

#define M_PI 3.14159265358979323846
#define ul unsigned long

using namespace std;
float area_circle;
float perimetr_circle;
float area_tri;
float perimetr_tri;

string tr = "triangle", ci = "circle";
int main() //����

{
    ifstream fin("../inputfiles/input.txt", ios::in);
    vector<string> str;
    while (!fin.eof()) {
        string tmp;        // Считываем строку
        getline(fin, tmp); //Считываем до первого пробела
        if (tmp == "")
            continue;
        str.push_back(tmp); //Значение строку в файл
    }
    fin.close();
    int N = str.size();
    for (int i = 0; i < N; i++) {
        while (str[i].find("  ", 0) != (ul)(-1)) {
            str[i].replace(str[i].find("  ", 0), 2, " ");
        }
        cout << str[i] << endl; //Вывод строки
    }
    circle c;
    triangle tri;
    for (int i = 0; i < N; i++) {
        int j = 0, bal = 0;
        string func = "";
        int K = str[i].size();
        while (str[i][j] != '('
               && str[i][j] != ')') // Проверка названия фигуры + регистр
        {
            func += tolower(str[i][j]);
            j++;
            if (j >= K)
                break;
        }
        if (str[i][j] == '(')
            bal++;
        if (!check_function(func))
            break;
        if (str[i][j] == ')') // Проверка на первую скобку(
        {
            cout << "Error at column " << j + 1 << ": expected '('";
            break;
        }
        if (j < K)
            j++;
        else
            break;
        if (str[i][j] == '(')
            bal++;
        if (func == tr
            && str[i][j] != '(') //Проверка на вторую скобку, если треугольник
        {
            cout << "Error at column " << j + 1 << ": expected '('";
            break;
        }
        //Цифры
        if (func == ci)
            c = Circle(str[i], j);
        if (func == tr) {
            if (j < K)
                j++;
            tri = Triangle(str[i], j);
        }
        while (str[i][j] == ')') {
            if (str[i][j] == ')' && bal > 0)
                bal--;
            j++;
        }
        if (++j < K) {
            cout << "\nError at column " << j + 1 << ": unexpected token";
        }
        if (func == ci)
            print_circle(c, i);
        if (func == tr)
            print_tri(tri, i);
    }
    return 0;
}
