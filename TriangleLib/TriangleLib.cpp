#include <iostream>
#include "triangle.h"

int Triangle::get_a() { return a; };
int Triangle::get_h() { return h; }

void Triangle::set_a(int side) { 
  if (a > 0) a = side; 
  else a = 1;
}
void Triangle::set_h(int height) { if (h > 0) h = height; else h = 1;}
double Triangle::get_S() { S = (a * h) / 2.0; return S; }
