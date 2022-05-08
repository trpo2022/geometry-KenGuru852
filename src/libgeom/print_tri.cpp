#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>
#include <libgeom/print_tri.h>
#include <math.h>
#include <string>
#include <vector>

#define M_PI 3.14159265358979323846

void print_tri(triangle c, int i)
{
    std::cout << i + 1 << ". " << c.func_name << std::endl;
    std::cout << "\t perimetr = " << c.per << std::endl;
    std::cout << "\t area = " << c.area << std::endl;
}

