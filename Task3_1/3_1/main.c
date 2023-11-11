#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <float.h>
#include <stdlib.h>

/**
* @brief Функция расчета по заданной формуле.
* @return Возвращает значение фенкции.
*/
double gety();

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
	double x;
	gety();
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

double gety()
{
	const double detx = 0.05;
	for (double x = 0; x <= 0.8 + detx; x += detx)
	{
		if (checkx(x))
		{
			double y = tan(x) - (1 / 3) * pow(tan(x), 3) + (1 / 5) * pow(tan(x), 5) - (1 / 3);
			printf("x = %lf y = %lf\n", x, y);
		}
		else
		{
			printf("%s", "В данной точке функция не определена.");
		}
	}
}