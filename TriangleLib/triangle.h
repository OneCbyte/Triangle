#pragma once

class Triangle {
private:
	int a, h;
	double S;
public:
	// Ïî óìîë÷àíèþ
	Triangle() : a(0), h(0) {}

	// èíèöèàëèçàöèÿ 
	Triangle(int side, int height);

	// ãåòåðû
	int get_a() const;
	int get_h() const ;

	// ñåòòåðû
	void set_a(int side);
	void set_h(int height);

	double get_S() const;
};
