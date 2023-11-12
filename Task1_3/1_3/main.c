#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>

double get_value();
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
	printf("%s", "Insert force: "); 
	double force = get_value();
	printf("%s", "Insert arbeit: "); 
	double arbeit = get_value();
	check(force, arbeit);
	printf("The path traveled by the car: %lf meters", getS(force, arbeit));
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

double get_value()
{
	double value;
	int result = scanf_s("%lf", &value);
	if (result != 1 || value <= 0)
	{
		errno = EIO;
		perror("Invalid value entered!!!");
		abort();
	}
	return value;
}