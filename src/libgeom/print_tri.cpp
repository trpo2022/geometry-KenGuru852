#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>
#include <libgeom/print_tri.h>
#include <math.h>
#include <string>
#include <vector>

void print_tri(triangle c, int i)
{
    std::cout << i + 1 << ". " << c.func_name << std::endl;
    std::cout << "\t perimetr = " << c.per << std::endl;
    std::cout << "\t area = " << c.area << std::endl;
}
