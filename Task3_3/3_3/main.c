#include <stdio.h>
#include <locale.h>
#include <errno.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>

/**
* @brief Функция для вычисления рекуррентного члена ряда.
* @param x Параметр функции, аппроксимируемой рядом.
* @param k Индекс члена ряда.
* @return Значение рекуррентного члена.
*/
double get_recurrent(double x, double k);

/**
* @brief Функция для вычисления суммы ряда.
* @param x Показатель степени.
* @return Значение 3 в степени x.
*/
double get_series_sum(double x, double e);

/**
* @brief Функция для вычисления значения функции.
* @param x - аргумент функции.
* @return Значение функции.
*/
double get_function(double x);

/**
* @brief Функция проверки ввода шага на правильность.
* @param h - шаг функции.
* @remarks Экстренное завершение программы, в случае неправильного ввода.
*/
void check_step(double h);

/**
* @brief Функция проверки шага на правильность.
* @param message - сообщение пользователю.
* @remarks Экстренное завершение программы, в случае неправильного ввода.
* @return Возвращает значение в случае успеха.
*/
double get_value(const char* message);

/**
* @brief Функция проверки отрезка на существование.
* @param a - начало отрезка.
* @param b - конец
отрезка.
*/
void check_segment(const double a, const double b);

/**
* @brief Функция проверки на правильность точности вычислений.
* @remarks Экстренное завершение программы, в случае неправильного ввода.
* @return Возвращает значение в случае успеха.
*/
void check_epsilon(double e, double x);

/**
* @brief Функция расчёта первого элемента последовательности.
* @param x - аргумент функции.
* @return Возвращает значение первого элемента последовательности.
*/
double get_first_element(double x);

/**
* @brief Точка входа в программу.
* @return Возвращает 0 в случае успеха.
*/
int main()
{
	setlocale(LC_ALL, "RU");

	const double a = get_value("Введите начало интервала: ");
	const double b = get_value("Введите конец интервала: ");
	check_segment(a, b);
	const double h = get_value("Введите шаг функции: ");
	check_step(h);
	const double e = get_value("Введите точность вычислений: ");
	double x = a;
	check_epsilon(e, x);
	
	while (x - b <= DBL_EPSILON)
	{
		printf_s("%10.2lf | %25.15lf | %.15lf \n", x, get_function(x), get_series_sum(x, e));
		x += h;
	}

	return 0;
}


double get_series_sum(double x, double e)
{
	double current = 1;
	double sum = current;
	double k = 0;

	while (get_function(x) - sum > e)
	{
		current *= get_recurrent(x, k);
		sum += current;
		k++;
	}
	return sum;
}

double get_recurrent(double x, double k)
{
	return pow(x, 2) / ((2 * k + 2) * (2 * k + 1));
}

double get_function(double x)
{
		return (exp(x) + exp(-x)) / 2;
}

void check_step(double h)
{
	if (h < DBL_EPSILON)
	{
		puts("Неверно введено значение!");
		abort();
	}
}

void check_segment(const double a, const double b)
{
	if (a - b > -DBL_EPSILON)
	{
		puts("Неверно введен интервал.");
		abort();
	}
}

double get_value(const char* message)
{
	double value;
	printf("%s", message);
	int result = scanf_s("%lf", &value);

	if (result != 1)
	{
		errno = EIO;
		perror("Ошибка ввода");
		abort();
	}
	return value;
}

void check_epsilon(double e, double x)
{
	if (e < DBL_EPSILON || e - get_first_element(x) > DBL_EPSILON)
	{
		printf("Неверно введена тосность!");
		abort();
	}
}

double get_first_element(double x)
{
	double current = pow(x, 2) / 2;
	return current;
}