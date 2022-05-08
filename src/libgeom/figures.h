#pragma once
#include <string>
#include <vector>
struct Point {
    float x;
    float y;
    Point(){};
    Point(float _x, float _y) : x(_x), y(_y){};
};

struct circle {
    Point center;
    std::string func_name;
    float per;
    float area;
    float rad;
    std::string position;
    std::vector<std::string> intersections;
    circle(){};
    circle(Point _center,
           std::string _func_name,
           float _per,
           float _area,
           float _rad)
        : center(_center),
          func_name(_func_name),
          per(_per),
          area(_area),
          rad(_rad){};
};

struct triangle {
    std::string func_name;
    float per;
    float area;
    triangle(){};
    triangle(std::string _func_name, float _per, float _area)
        : func_name(_func_name), per(_per), area(_area){};
};
