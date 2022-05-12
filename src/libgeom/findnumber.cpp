#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>
#include <libgeom/findnumber.h>
#include <math.h>
#include <string>
#include <vector>

std::string findnumber(std::string str, int& j) // Ищем числа в строке
{
    std::string num = "";
    int N = str.size();
    while (str[j] != ' ' && str[j] != ',' && str[j] != ')') //проверка на цифры
    {
        num += str[j];
        j++;
        if (j >= N)
            break;
    }
    if (str[j] == ',' && j < N)
        j++;
    return num;
}
