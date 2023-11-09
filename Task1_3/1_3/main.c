#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>

/**
* @brief Фукция проверки переменной F.
* @param f Аргумент функции.
* @param a Аргумент функции.
* @return Возвращает ошибку в случае успеха.
*/
double check(double f, double a);

/**
* @brief Функция расчета пути.
* @param F Аргумент функции.
* @param A Аргумент функции.
* @return Возвращает значение функции.
*/
double getS(double f, double a);

/**
* @brief Точка входа в программу.
* @return Возвращает 0 в случае успеха.
*/
int main()
{
	double f;
	double a;
	printf("%s", "Insert F: "); scanf_s("%lf", &f);
	printf("%s", "Insert A: "); scanf_s("%lf", &a);
	check(f, a);
	double s = getS(f, a);
	printf("The path traveled by the car: %lf meters", s);
	return 0;
}

double check(double f,double a)
{
	if ((f < 0) || (a < DBL_EPSILON))
	{
		printf("%s", "The entered data doesn't correspond to the task conditions.");
		abort();
	}
}

double getS(double f, double a)
{
	return (a * pow(10, 6)) / (f * pow(10, 3));
}