#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <float.h>
#include <stdlib.h>

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
* @brief Точка входа в программу. 
* @return Возвращает 0 в случае успеха.
*/
int main()
{
	const double detx = 0.05;
	double x;
	for (x = 0; x <= 0.8 + detx; x += detx)
	{
		if (checkx(x))
		{
			gety(x);
			printf("x = %lf y = %lf\n", x, gety(x));
		}
		else
		{
			printf("%s", "В данной точке функция не определена.");
		}
	}
	return 0;
}

bool checkx(double x)
{
	if (fabs(cos(x)) > DBL_EPSILON)
	{
		return true;
	}
	else
	{
		return false;
	}
}

double gety(double x)
{
	return tan(x) - (1 / 3) * pow(tan(x), 3) + (1 / 5) * pow(tan(x), 5) - (1 / 3);
}