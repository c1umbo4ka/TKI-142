#include <stdio.h>
#include <math.h>

/**
* @brief Функция расчёта по заданной формуле.
* @param x Аргумент функции.
* @param y Аргумент функции.
* @param z Аргумент функции.
* @return Возвращает значение функции.
*/
double getA(double x, double y, double z);


/**
* @brief Функция расчёта по заданной формуле.
* @param x Аргумент функции.
* @param y Аргумент функции.
* @param z Аргумент функции.
* @return Возвращает значение функции.
*/
double getB(double x, double y, double z);


/**
* @brief Точка входа в программу.
* @return Возвращает 0 в случае успеха.
*/
int main()
{
	const double x = 0.2;
	const double y = 0.004;
	const double z = 1.1;
	const double a = getA(x, y, z);
	const double b = getB(x, y, z);
	printf("x = %lf y = %lf z = %lf\n", x, y, z);
	printf("a = %lf b = %lf", a, b);
	return 0;
}

double getA(double x, double y, double z)
{
	return pow(sin(pow(x, 2) + z), 2) - sqrt(x / y);
}

double getB(double x, double y, double z)
{
	return (pow(x, 2) / z) + cos(pow((x + y), 3));
}