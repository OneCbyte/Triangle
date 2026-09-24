#pragma once

class Triangle {
private:
	int a, h;
	double S;
public:
	// По умолчанию
	Triangle() : a(0), h(0) {}

	// инициализация 
	Triangle(int side, int height) : a(side), h(height) {}

	// гетеры
	int get_a();
	int get_h();

	// сеттеры
	void set_a(int side);
	void set_h(int height);

	double get_S();
};
