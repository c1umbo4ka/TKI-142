﻿#define _USE_MATH_DEFINES
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

/**
* @brief Функция проверки переменной Radius.
* @param Radius Аргумент функции.
* @return Возвращает истину в случае успеха.
*/
double checkR(double Radius);

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
double getVolume(double Radius, double a);

/**
* @brief Функция расчета площади.
* @param Radius Аргумент функции.
* @param a Аргумент функции.
* @return Возвращает значение функции.
*/
double getSquare(double Radius, double a);

/**
* @brief Точка входа в программу.
* @return Возвращает 0 в случае успеха.
*/
int main()
{
	double Radius;
	double a;
	printf("%s", "Insert Radius: ");
	scanf_s("%lf", &Radius);
	printf("%s", "Insert a: ");
	scanf_s("%lf", &a);
	checkR(Radius);
	checkA(a);
	double V = getVolume(Radius, a);
	double S = getSquare(Radius, a);
	printf("Radius = %lf a = %lf\n", Radius, a);
	printf("Volume = %lf\n", V);
	printf("Square = %lf", S);
	return 0;
}

double checkR(double Radius)
{
	if (Radius <= 0)
	{
		printf("%s", "Error!!!");
		abort();
	}
}

double checkA(double a)
{
	if (a > M_PI || a <= 0)
	{
		printf("%s", "Error!!!");
		abort();
	}
}

double getVolume(double Radius, double a)
{
	double A = 2.0 * Radius * sin(a);
	double h = A / (2.0 * tan(a / 2.0));
	return (M_PI * pow((A / 2.0), 2) * h) / 3.0;
}

double getSquare(double Radius, double a)
{
	double A = 2.0 * Radius * sin(a);
	double l = A / (2.0 * sin(a / 2.0));
	return M_PI * Radius * (Radius + l);
}