#include <stdio.h>
#include <math.h>
#include <float.h>
#include <errno.h>
#include <stdlib.h>

/**
* @brief Функция считывающая количество членов последовательности.
* @remarks Экстренное завершение программы, в случае неправильного ввода.
* @return Количество членов последовательности.
*/
int get_count();

/**
* @brief Функция расчитывающая сумму членов последовательности.
* @param count - количество членов последовательности.
* @return Сумма последовательности.
*/
double get_sum(int count);

/**
* @brief Функция расчитывающая рекурентный член последовательности.
* @param k - номер члена последовательности.
* @return Значение рекурентного члена последовательности.
*/
double get_recurrent(int k);

/**
* @brief Точка входа в программу.
* @return Возвращает 0 в случае успеха.
*/
int main()
{
	printf("%s", "Insert end of the segment: ");
	int count = get_count();
	printf_s("Sum of %d sequence terms: %lf \n", count + 1, get_sum(count));
	return 0;
}

int get_count()
{
	int count;
	int result = scanf_s("%d", &count);

	if (result != 1 || count < 1)
	{
		errno = EIO;
		perror("Ошибка ввода");
		abort();
	}
	return count;
}

double get_sum(int count)
{
	double current = 1;
	double sum = current;
	for (int k = 0; k < count; k++)
	{
		current *= get_recurrent(k);
		sum += current;
	}
	return sum;
}

double get_recurrent(int k)
{
	return 1.0 / (4 * pow(k, 2) + 6 * k + 2);
}