#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>

/**
* @brief Фукция проверки переменных force и arbeit.
* @param force Аргумент функции.
* @param arbeit Аргумент функции.
* @return Возвращает ошибку в случае успеха.
*/
double check(double force, double arbeit);

/**
* @brief Функция расчета пути.
* @param force Аргумент функции.
* @param arbeit Аргумент функции.
* @return Возвращает значение функции.
*/
double getS(double force, double aarbeit);

/**
* @brief Точка входа в программу.
* @return Возвращает 0 в случае успеха.
*/
int main()
{
	double force;
	double arbeit;
	printf("%s", "Insert force: "); scanf_s("%lf", &force);
	printf("%s", "Insert arbeit: "); scanf_s("%lf", &arbeit);
	check(force, arbeit);
	double s = getS(force, arbeit);
	printf("The path traveled by the car: %lf meters", s);
	return 0;
}

double check(double force,double arbeit)
{
	if ((force < DBL_EPSILON) || (arbeit < DBL_EPSILON))
	{
		printf("%s", "The entered data doesn't correspond to the task conditions.");
		abort();
	}
}

double getS(double force, double arbeit)
{
	const double mega = pow(10, 6);
	const double kilo = pow(10, 3);
	return (arbeit * mega) / (force * kilo);
}