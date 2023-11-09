#include <stdio.h>
#include <math.h>
#include <float.h>

/**
* @brief Функция расчёта по заданной формуле.
* @param x Аргумент функции.
* @param a Аргумент функции.
* @return Возвращает значение функции.
*/
double getY(double x, double a);

/**
* @brief Точка входа в программу.
* @return Возвращает 0 в случае успеха.
*/
int main()
{
	const double a = 20.3;
	double x = 0;
	printf("%s", "Insert x: ");
	scanf_s("%lf", &x);
	double y = getY(x, a);
	printf("x = %lf\n", x);
	printf("y = %lf", y);
	return 0;
}

double getY(double x, double a)
{
	if (x - 1 > DBL_EPSILON)
	{
		return log10(x + 1);
	}
	else
	{
		return sin(2 * sqrt(abs(a * x)));
	}
}