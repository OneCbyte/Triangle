#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");
    int a, h;
    std::cout << "Введите основание треугольника: \n";
    std::cin >> a;
    std::cout << "Введите высоту треугольника: \n";
    std::cin >> h;
    std::cout << "Площадь - " << ((double)a*h/2);
    return 0;
}

