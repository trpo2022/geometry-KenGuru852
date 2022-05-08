#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>
#include <libgeom/isdigit.h>
#include <math.h>
#include <string>
#include <vector>

#define M_PI 3.14159265358979323846
bool is_number(std::string n, int j) // Ошибка, если что-то другое вместо цифры
{
    int N = n.size();
    for (int i = 0; i < N; i++) {
        if (!isdigit(n[i]) && n[i] != '-' && n[i] != '.') {
            std::cout << "Error at column " << j - (N - i - 1)
                      << ": expected '<double>'";
            return false;
        }
    }
    return true;
}
