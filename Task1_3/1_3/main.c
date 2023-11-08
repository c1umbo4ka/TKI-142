#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
* @brief Фукция проверки переменной F.
* @param F Аргумент функции.
* @return Возвращает ошибку в случае успеха.
*/
double checkF(double F);

/**
* @brief Фукция проверки переменной A.
* @param A Аргумент функции.
* @return Возвращает ошибку в случае успеха.
*/
double checkA(double A);

/**
* @brief Функция расчета пути.
* @param F Аргумент функции.
* @param A Аргумент функции.
* @return Возвращает значение функции.
*/
double getS(double F, double A);

/**
* @brief Точка входа в программу.
* @return Возвращает 0 в случае успеха.
*/
int main()
{
	double F;
	double A;
	printf("%s", "Insert F: "); scanf_s("%lf", &F);
	printf("%s", "Insert A: "); scanf_s("%lf", &A);
	checkF(F);
	checkA(A);
	double S = getS(F, A);
	printf("The path traveled by the car: %lf meters", S);
	return 0;
}

double checkF(double F)
{
	if (F < 0)
	{
		printf("%s", "The entered data doesn't correspond to the task conditions.");
		abort();
	}
}

double checkA(double A)
{
	if (A < 0)
	{
		printf("%s", "The entered data doesn't correspond to the task conditions.");
		abort();
	}
}

double getS(double F, double A)
{
	return (A * pow(10, 6)) / (F * pow(10, 3));
}