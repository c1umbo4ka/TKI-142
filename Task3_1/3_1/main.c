#include <stdio.h>
#include <math.h>

/**
* @brief Функция расчета по заданной формуле.
* @return Возвращает значение фенкции.
*/
double gety();

/**
* @brief Точка входа в программу. 
* @return Возвращает 0 в случае успеха.
*/
int main()
{
	gety();
	return 0;
}

double gety()
{
	const double detx = 0.05;
	for (double x = 0; x <= 0.8 + detx; x += detx)
	{
		double y = tan(x) - (1 / 3) * pow(tan(x), 3) + (1 / 5) * pow(tan(x), 5) - (1 / 3);
		printf("x = %lf y = %lf\n", x, y);
	}
}