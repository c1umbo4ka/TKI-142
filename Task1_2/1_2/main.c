#define _USE_MATH_DEFINES
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <float.h>

/**
* @brief Функция проверки переменной Radius.
* @param Radius Аргумент функции.
* @return Возвращает истину в случае успеха.
*/
double checkR(double radius);

/**
* @brief Функция проверки переменной a.
* @param a Аргумент функции.
* @return Возвращает истину в случае успеха.
*/
double checkA(double a);

/**
* @brief Функция расчета объёма.
* @param Radius Аргумент функции.
* @param a Аргумент функции.
* @return Возвращает значение функции.
*/
double getVolume(double radius, double a);

/**
* @brief Функция расчета площади.
* @param Radius Аргумент функции.
* @param a Аргумент функции.
* @return Возвращает значение функции.
*/
double getSquare(double radius, double a);

/**
* @brief Точка входа в программу.
* @return Возвращает 0 в случае успеха.
*/
int main()
{
	double radius;
	double a;
	printf("%s", "Insert Radius: ");
	scanf_s("%lf", &radius);
	printf("%s", "Insert a: ");
	scanf_s("%lf", &a);
	checkR(radius);
	checkA(a);
	double v = getVolume(radius, a);
	double s = getSquare(radius, a);
	printf("Radius = %lf a = %lf\n", radius, a);
	printf("Volume = %lf\n", v);
	printf("Square = %lf", s);
	return 0;
}

double checkR(double radius)
{
	if (radius <= DBL_EPSILON)
	{
		printf("%s", "Error!!!");
		abort();
	}
}

double checkA(double a)
{
	if (a - M_PI > - DBL_EPSILON || a <= DBL_EPSILON)
	{
		printf("%s", "Error!!!");
		abort();
	}
}

double getVolume(double radius, double a)
{
	double A = 2.0 * radius * sin(a);
	double h = A / (2.0 * tan(a / 2.0));
	return (M_PI * pow((A / 2.0), 2) * h) / 3.0;
}

double getSquare(double radius, double a)
{
	double A = 2.0 * radius * sin(a);
	double l = A / (2.0 * sin(a / 2.0));
	return M_PI * radius * (radius + l);
}
