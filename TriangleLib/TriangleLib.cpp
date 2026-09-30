#include <iostream>
#include "triangle.h"

Triangle::Triangle(int a, int h): a(1), h(1) {
  set_a(a);
  set_h(h);
}
int Triangle::get_a() const { return a; }
int Triangle::get_h() const { return h; }

void Triangle::set_a(int side) { 
  if (a > 0) a = side; 
  else a = 1;
}
void Triangle::set_h(int height) { if (h > 0) h = height; else h = 1;}
double Triangle::get_S() const { S = (a * h) / 2.0; return S; }
