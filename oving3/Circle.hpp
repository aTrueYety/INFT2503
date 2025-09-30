#pragma once
#include <iostream>
using namespace std;

const double pi = 3.141592;

class Circle {
  public:
    Circle(double radius_);
    int get_area() const;
    double get_circumference() const;
  private:
    double radius;
};

// test function (so main.cpp can call it)
void testCircle();
