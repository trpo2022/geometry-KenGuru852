#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>
#include <libgeom/print_circle.h>
#include <math.h>
#include <string>
#include <vector>

void print_circle(circle c, int i)
{
    std::cout << i + 1 << ". " << c.func_name << std::endl;
    std::cout << "\t perimetr = " << c.per << std::endl;
    std::cout << "\t area = " << c.area << std::endl;
    int N = c.intersections.size();
    if (N > 0) {
        std::cout << "\t intersection:" << std::endl;
        for (int i = 0; i < N; i++) {
            std::cout << "\t\t " << c.intersections[i] << std::endl;
        }
    }
}
