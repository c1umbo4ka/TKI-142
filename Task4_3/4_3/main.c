#include <stdio.h>
#include <locale.h>
#include <errno.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/**
* @brief Выбор заполнения массива.
*/
enum array_input_choice
{
	/**
	* @brief Ручной способ.
	*/
	MANUAL = 1,
	/**
	* @brief Заполнение массива случайными числами.
	*/
	RANDOM = 2
};

/**
* @brief Функция для считывания элементов массива с клавиатуры.
* @param size - длина массива.
* @param my_array - массив.
*/
void get_manual_input_array(int** my_array, size_t n, size_t m, const int minimum_limit, const int maximum_limit);

/**
* @brief Функция для заполнения массива случайными числами.
* @param size - длина массива.
* @param my_array - массив.
*/
void get_random_input_array(int** my_array, size_t n, size_t m, const int minimum_limit, const int maximum_limit);

/**
* @brief Функция для печати массива.
* @param array - массив.
* @param size - длина массива.
*/
void print_array(int** my_array, size_t n, size_t m);

/**
* @brief Функция для считывания значения с клавиатуры.
* @param message - сообщение пользователю.
* @remarks Экстренное завершение программы, в случае неправильного ввода.
* @return Значение с клавиатуры.
*/
int get_value(const char* message);

/**
* @brief Функция для проверки длинны массива.
* @param int_size - длина массива.
* @remarks Экстренное завершение программы, в случае неправильной длинны массива.
*/
void true_size(int n, int m);

/**
* @brief Функция для проверки массива.
* @param my_array - первый массив.
* @param second_array - второй массив.
* @param third_array - третий массив.
* @remarks Экстренное завершение программы, в случае несуществования массива.
*/
void true_array(int** my_array);

/**
* @brief Функция проверки интервала массива на правильность.
* @param minimum_limit - минимальный возможный элемент массива.
* @param maximum_limit - максимальный возможный элемент массива.
*/
void check_segment(int minimum_limit, const int maximum_limit);


int get_index_of_max_in_array_column(int** my_array, size_t n, size_t m, int j);


int** get_first_array(int** my_array, size_t n, size_t m);


int get_maximum_modulus_element(int** my_array, size_t n, size_t m);


int** get_second_array(int** my_array, size_t n, size_t m);

/**
* @brief Точка входа в программу.
* @return Возвращает 0 в случае успеха.
*/
int main()

{
	setlocale(LC_ALL, "RU");

	size_t n = get_value("Введите количество строк матрицы: ");
	size_t m = get_value("Введите количество столбцов матрицы: ");
	true_size(n, m);

	const int minimum_limit = get_value("Введите минимум массива: ");
	const int maximum_limit = get_value("Введите максимум массива: ");
	check_segment(minimum_limit, maximum_limit);

	int** my_array = (int*)malloc(n * m * sizeof(int));

	true_array(my_array);

	puts("Введите номер соответствующий способу, которым вы хотите ввести массив:\n");
	printf_s("%d - для заполнения массива с клавиатуры\n", MANUAL);
	printf_s("%d - для заполнения массива случайными числами\n", RANDOM);

	int choice = get_value("");

	enum array_input_choice user_input = (enum user_input)choice;

	switch (user_input)
	{
	case MANUAL:
	{
		get_manual_input_array(my_array, n, m, minimum_limit, maximum_limit);
		break;
	}
	case RANDOM:
	{
		get_random_input_array(my_array, n, m, minimum_limit, maximum_limit);
		break;
	}
	default:
	{
		errno = EDOM;
		perror("Ошибка ввода");
		return EXIT_FAILURE;
	}
	}
	
	puts("Исходный массив:");
	print_array(my_array, n, m);

	puts("Ответ на первое задание:");
	print_array(get_first_array(my_array, n, m), n, m);

	puts("Ответ на третье задание:");
	print_array(get_second_array(my_array, n, m), n, m);

	return 0;
}

int get_value(const char* message)
{
	int value;
	printf_s("%s", message);
	int result = scanf_s("%d", &value);
	if (result != 1)
	{
		errno = EIO;
		perror("Ошибка ввода");
		abort();
	}
	return value;
}

void true_size(int n, int m)
{
	if (n <= 0 || m <= 0)
	{
		errno = EIO;
		perror("Ошибка ввода");
		abort();
	}
}

void true_array(const int** my_array)
{
	if (my_array == NULL)
	{
		errno = EIO;
		perror("Ошибка ввода");
		abort();
	}
}

void get_manual_input_array(int** my_array, size_t n, size_t m, const int minimum_limit, const int maximum_limit)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("a[%d][%d] = ", i, j);
			int c = get_value("");
			if (c < minimum_limit || c > maximum_limit)
			{
				errno = EIO;
				perror("Ошибка ввода");
				abort();
			}
			my_array[i * m + j] = c;
		}
	}
}

void get_random_input_array(int** my_array, size_t n, size_t m, const int minimum_limit, const int maximum_limit)
{
	unsigned int ttime = time(NULL);
	srand(ttime);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			my_array[i * m + j] = minimum_limit + rand() % (maximum_limit - minimum_limit + 1);
		}
	}
}

void check_segment(const int minimum_limit, const int maximum_limit)
{
	if (minimum_limit > maximum_limit)
	{
		puts("Неверно введен интервал.");
		abort();
	}
}

void print_array(int** my_array, size_t n, size_t m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%5d ", my_array[i * m + j]);
		}
		printf("\n");
	}
}
int get_index_of_max_in_array_column(int** my_array, size_t n, size_t m, int j)
{
	int max = my_array[j];
	int number = 0;
	for (int i = 0; i < n; i++)
	{
		if (max < my_array[i * m + j])
		{
			max = my_array[i * m + j];
			number = i * m + j;
		}
	}
	return number;
}

int** get_first_array(int** my_array, const size_t n, const size_t m)
{
	for (int j = 0; j < m; j++)
	{
		my_array[get_index_of_max_in_array_column(my_array, n, m, j)] = 0;
	}
	return my_array;
}

int get_maximum_modulus_element(int** my_array, size_t n, size_t m)
{
	int max = abs(my_array[0]);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (max < abs(my_array[i * m + j]))
			{
				max = abs(my_array[i * m + j]);
			}
		}
	}
	return max;
}

int get_size_of_second_array(int** my_array, size_t n, size_t m)
{
	int number_of_added_lines = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (abs(my_array[i * m + j]) == get_maximum_modulus_element(my_array, n, m))
			{
				number_of_added_lines += 1;
				i++;
				j = 0;
				if (i > n)
				{
					break;
				}
			}
		}
	}
	return ((n + number_of_added_lines) * m);
}

int** get_second_array(int** my_array, size_t n, size_t m)
{
	int** second_array = (int**)realloc(my_array, get_size_of_second_array(my_array, n, m) * sizeof(int**));
	int k = get_size_of_second_array(my_array, n, m);
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (abs(my_array[i * m + j]) == get_maximum_modulus_element(my_array, n, m))
			{
				for (int l = k; l > i * m + j; l--)
				{
					my_array[l-1] = my_array[l - m - 1];
					my_array[i * m + j] = 0;
					k++;
					i+=2;
					j = 0;
				}
			}
		}
	}

	return second_array;
}