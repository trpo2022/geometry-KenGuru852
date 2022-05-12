#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>
#include <libgeom/check.h>
#include <math.h>
#include <string>
#include <vector>

bool check_function(std::string f) // Вывод ошибки в названии фигуры
{
    std::string tr = "triangle", ci = "circle";
    if (f == ci || f == tr)
        return true;
    else {
        std::cout << "Error at column 0: expected 'circle' or 'triangle'";
        return false;
    }
}
