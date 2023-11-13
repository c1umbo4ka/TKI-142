#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <float.h>
#include <stdlib.h>
#include <errno.h>

/**
* @brief Функция расчета по заданной формуле.
* @param x Аргумент функции.
* @return Возвращает значение фенкции.
*/
double gety(double x);

/**
* @brief Функция проверки переменной x.
* @param x Аргумент функции.
* @return Возвращает истину в случае успеха.
*/
bool checkx(double x);

/**
* @brief Функция проверки отрезка на правильность.
* @param start Аргумент функции.
* @param end Аргумент функции.
* @return Возвращает ошибку в случае успеха.
*/
double check_segment(double start, double end);

/**
* @brief Функция проверки шага на правильность.
* @param detx Аргумент функции.
* @return Возвращает ошибку в случае успеха.
*/
double check_detx(double detx);

/**
* @brief Функция проверки ввода на правильность.
* @return Возвращает значение в случае успеха.
*/
double get_value();

/**
* @brief Точка входа в программу. 
* @return Возвращает 0 в случае успеха.
*/
int main()
{
	printf("%s", "Insert beginning of the segment: ");
	double start = get_value();
	printf("%s", "Insert end of the segment: ");
	double end = get_value();
	check_segment(start, end);
	printf("%s", "Insert step: ");
	double detx = get_value();
	check_detx(detx);
	for (double x = start; x <= end; x += detx)
	{
		if (checkx(x))
		{
			printf("x = %lf y = %lf\n", x, gety(x));
		}
		else
		{
			printf("x = %lf At this point the function is not defined.", x);
		}
	}
	return 0;
}

bool checkx(double x)
{
	if (fabs(cos(x)) > -DBL_EPSILON)
	{
		return true;
	}
	return false;
}

double gety(double x)
{
	return tan(x) - (1.0 / 3) * pow(tan(x), 3) + (1.0 / 5) * pow(tan(x), 5) - (1.0 / 3);
}

double check_segment(double start, double end)
{
	if (start - end > -DBL_EPSILON)
	{
		printf("%s", "Incorrect segment specified.");
		abort();
	}
}

double check_detx(double detx)
{
	if (detx <= DBL_EPSILON)
	{
		printf("%s", "The step is set incorrectly.");
		abort();
	}
}

double get_value()
{
	double value;
	int result = scanf_s("%lf", &value);
	if (result != 1)
	{
		errno = EIO;
		perror("Invalid value entered!!!");
		abort();
	}
	return value;
}