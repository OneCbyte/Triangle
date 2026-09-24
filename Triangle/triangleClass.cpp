#include <iostream>
#include "triangle.h"

int Triangle::get_a() { return a; };
int Triangle::get_h() { return h; }

void Triangle::set_a(int side) { a = side; }
void Triangle::set_h(int height) { h = height; }
double Triangle::get_S() { S = (a * h) / 2.0; return S; }