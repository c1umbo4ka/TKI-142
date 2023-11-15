#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <errno.h>
#include <locale.h>
#include <stdio.h>

/**
* @brief Пользовательский ввод.
*/
enum user_input
{
	/**
	* @brief Радианы.
	*/
	RADIANS = 1,
	/**
	* @brief Градусы.
	*/
	DEGREES = 2
};

/**
* @brief Получает целое значение.
* @remarks Экстренное завершение программы, в случае неправильного ввода.
* @return Целое значение.
*/
int get_choice();

/**
* @brief Функция для проверки ввода радиан или градусов.
* @remarks Экстренное завершение программы, в случае неправильного ввода.
* @return Количество радиан или градусов.
*/
double get_value();

/**
* @brief Функция для введения радиан.
* @return Количество радиан.
*/
double get_radians();

/**
* @brief Функция для подсчёта градусов.
* @param radians - введённое количество радиан.
* @return Количество градусов.
*/
double calculate_degrees(double radians);

/**
* @brief Функция для введения градусов.
* @return Количество градусов.
*/
double get_degrees();

/**
* @brief Функция для подсчёта радиан.
* @param degrees - введённое количество градусов.
* @return Количество радиан.
*/
double calculate_radians(double degrees);

/**
* @brief Точка входа в программу.
* @return \c 0 в случае успеха, иначе \c 1.
*/
int main()
{
	setlocale(LC_ALL, "RU");

	puts("Введите номер соответствующий заданию:\n");
	printf_s("%d - для вычисление градусов\n", RADIANS);
	printf_s("%d - для вычисление радиан\n", DEGREES);

	int choice = get_choice();

	enum UserInput user_choice = (enum user_input)choice;

	switch (user_choice)
	{
	case RADIANS:
	{
		double radians = get_radians();
		double degrees = calculate_degrees(radians);
		printf_s("%lf радиан = %lf°", radians, degrees);
		break;
	}
	case DEGREES:
	{
		double degrees = get_degrees();
		double radians = calculate_radians(degrees);
		printf_s("%lf° = %lf радиан", degrees, radians);
		break;
	}
	default:
	{
		errno = EDOM;
		perror("Ошибка ввода");
		return EXIT_FAILURE;
	}
	}
	return EXIT_SUCCESS;
}


int get_choice()
{
	int choice;
	int result = scanf_s("%d", &choice);
	if (result != 1)
	{
		errno = EIO;
		perror("Ошибка ввода");
		abort();
	}

	return choice;
}

double get_value()
{
	double value;
	int result = scanf_s("%lf", &value);
	if (result != 1)
	{
		errno = EIO;
		perror("Введено неправильное значение");
		abort();
	}
	return value;
}

double get_radians()
{
	puts("Введите количество радиан:");
	double radians = get_value();
	return radians;
}

double calculate_degrees(double radians)
{
	const double to_degrees = 180 / M_PI;
	return radians * to_degrees;
}

double get_degrees()
{
	puts("Введите количество градусов:");
	double degrees = get_value();
	return degrees;
}

double calculate_radians(double degrees)
{
	const double to_radians = 180 * M_PI;
	return degrees * to_radians;
}