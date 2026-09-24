#include <iostream>
#include "triangle.h"

int main()
{
    setlocale(LC_ALL, "rus");
    int a, h;
    Triangle triangle;
    std::cout << "Введите основание треугольника: \n";
    std::cin >> a;
    triangle.set_a(a);
    std::cout << "Введите высоту треугольника: \n";
    std::cin >> h;
    triangle.set_h(h);
    std::cout << "Площадь - " << triangle.get_S();
    return 0;
}

