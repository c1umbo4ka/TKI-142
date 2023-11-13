#include <stdio.h>
#include <math.h>
#include <float.h>

/**
* @brief Функция расчёта по заданной формуле.
* @param x Аргумент функции.
* @return Возвращает значение функции.
*/
double getY(double x);

/**
* @brief Точка входа в программу.
* @return Возвращает 0 в случае успеха.
*/
int main()
{
	double x = 0;
	printf("%s", "Insert x: ");
	scanf_s("%lf", &x);
	printf("x = %lf\n", x);
	printf("y = %lf", getY(x));
	return 0;
}

double getY(double x)
{
	const double a = 20.3;
	if (x - 1 > - DBL_EPSILON)
	{
		return log10(x + 1);
	}
	return sin(2 * sqrt(abs(a * x)));
}