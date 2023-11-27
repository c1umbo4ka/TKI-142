﻿#include <stdio.h>
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
void get_manual_input_array(int* my_array, size_t size, const int minimum_limit, const int maximum_limit);

/**
* @brief Функция для заполнения массива случайными числами.
* @param size - длина массива.
* @param my_array - массив.
*/
void get_random_input_array(int* my_array, size_t size, const int minimum_limit, const int maximum_limit);

/**
* @brief Функция для печати массива.
* @param array - массив.
* @param size - длина массива.
*/
void print_array(int* array, size_t size);

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
void true_size(int int_size);

/**
* @brief Функция для проверки массива.
* @param my_array - первый массив.
* @param second_array - второй массив.
* @param third_array - третий массив.
* @remarks Экстренное завершение программы, в случае несуществования массива.
*/
void true_array(int* my_array);

/**
* @brief Функция проверки интервала массива на правильность.
* @param minimum_limit - минимальный возможный элемент массива.
* @param maximum_limit - максимальный возможный элемент массива.
*/
void check_segment(const int minimum_limit, const int maximum_limit);

/**
* @brief Функция для нахождения индекса минимального положительного элемента массива.
* @param my_array - первый массив.
* @param size - длина массива.
* @return Индекс минимального положительного элемента массива.
*/
size_t get_index_of_minimum_positive_element(int* my_array, size_t size);

/**
* @brief Функция для нахождения первого положительного элемента массива.
* @param my_array - первый массив.
* @param size - длина массива.
* @return Максимальный элемент массива.
*/
size_t get_index_of_first_positive_element(int* my_array, size_t size);

/**
* @brief Функция для нахождения длины второго массива.
* @param my_array - первый массив.
* @param size - длина первого массива.
* @return Длина второго массива.
*/
int get_size_of_second_array(int* my_array, size_t size);

/**
* @brief Функция для заполнения третьего массива.
* @param my_array - первый массив.
* @param size - старая длина массива.
* @return Третий массив.
*/
int* get_third_array(int* my_array, size_t size);

/**
* @brief Функция для получения второго массива.
* @param my_array - первый массив.
* @param size - старая длина массива.
* @param size_of_second_array - длина второго массива.
* @return Второй массив.
*/
int* get_second_array(int* my_array, size_t size, size_t size_of_second_array);

/**
* @brief Функция считывания размера массива.
* return Размер массива
*/
size_t get_size();

/**
* @brief Функция проверки наличия положительных элементов в массиве.
* @param my_array - массив.
* @param size - размер массива.
* @return Возвращает истину в случае успеха.
*/
bool check_positive_elements(int* my_array, size_t size);

/**
* @brief Функция для заполнения первого массива.
* @param my_array - массив.
* @param size - размер массива.
* @return Первый массив.
*/
int* get_first_array(int* my_array, size_t size);

/**
* @brief Точка входа в программу.
* @return Возвращает 0 в случае успеха.
*/
int main()
{
	setlocale(LC_ALL, "RU");

	size_t size = get_size();

	const int minimum_limit = get_value("Введите минимум массива: ");
	const int maximum_limit = get_value("Введите максимум массива: ");
	check_segment(minimum_limit, maximum_limit);

	int* my_array = (int*)malloc(size * sizeof(int));
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
		get_manual_input_array(my_array, size, minimum_limit, maximum_limit);
		break;
	}
	case RANDOM:
	{
		get_random_input_array(my_array, size, minimum_limit, maximum_limit);
		break;
	}
	default:
	{
		errno = EDOM;
		perror("Ошибка ввода");
		return EXIT_FAILURE;
	}
	}

	if (check_positive_elements(my_array, size))
	{
		
		puts("Ответ на первое задание:");
		print_array(get_first_array(my_array, size), size);
	}
	else 
	{
		puts("В массиве нет положительных чисел.");
	}

	puts("Ответ на второе задание:");
	print_array(get_second_array(my_array, size, get_size_of_second_array(my_array, size)), get_size_of_second_array(my_array, size));

	puts("Ответ на третье задание:");
	print_array(get_third_array(my_array, size), size);
	
	true_array(my_array);
	free(my_array);
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

void true_size(int int_size)
{
	if (int_size <= 0)
	{
		errno = EIO;
		perror("Ошибка ввода");
		abort();
	}
}

void true_array(int* my_array)
{
	if (my_array == NULL)
	{
		errno = EIO;
		perror("Ошибка ввода");
		abort();
	}
}

void get_manual_input_array(int* my_array, size_t size, const int minimum_limit, const int maximum_limit)
{
	for (size_t i = 0; i < size; i++)
	{
		printf("Введите число от %d до %d: ", minimum_limit, maximum_limit);
		int c = get_value("");
		if (c < minimum_limit || c > maximum_limit)
		{
			errno = EIO;
			perror("Ошибка ввода");
			abort();
		}
		my_array[i] = c;
	}
}

void get_random_input_array(int* my_array, size_t size, const int minimum_limit, const int maximum_limit)
{
	unsigned int ttime = time(NULL);
	srand(ttime);
	for (size_t i = 0; i < size; i++)
	{
		my_array[i] = minimum_limit + rand() % (maximum_limit - minimum_limit + 1);
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

void print_array(int* array, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		printf("%Iu %d\n", i, array[i]);
	}
}

size_t get_index_of_minimum_positive_element(int* my_array, size_t size)
{
	{
		int minimum_positive_element = my_array[get_index_of_first_positive_element(my_array, size)];
		int number = 0;
		for (size_t i = 0; i < size; i++)
		{
			if (minimum_positive_element > my_array[i] && my_array[i] > 0)
			{
				minimum_positive_element = my_array[i];
				number = i;
			}
		}
		return number;
	}
}

size_t get_index_of_first_positive_element(int* my_array, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (my_array[i] > 0)
		{
			return i;
			break;
		}
	}
}

int* get_third_array(int* my_array, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		if ((i % 2) == 0)
		{
			my_array[i] = my_array[i] + i;
		}
		else
		{
			my_array[i] = my_array[i] - i;
		}
	}
	return my_array;
}

int get_size_of_second_array(int* my_array, size_t size)
{
	int quantity_of_elements_removed = 0;
	for (int i = 0; i < size; i++)
	{
		if (my_array[i] % 10 % 2 != 0 && my_array[i] % 3 == 0)
		{
			quantity_of_elements_removed += 1;
		}
	}
	return (size - quantity_of_elements_removed);
}

int* get_second_array(int* my_array, size_t size, size_t size_of_second_array)
{
	int* second_array = (int*)malloc(size_of_second_array * sizeof(int));
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (my_array[i] % 10 % 2 == 0 || my_array[i] % 3 != 0)
		{
			second_array[j] = my_array[i];
			j++;
		}
	}
	return second_array;
}

size_t get_size()
{
	int int_size = get_value("Введите размер массива: ");
	true_size(int_size);
	size_t size = (size_t)(int_size);
	return size;
}

bool check_positive_elements(int* my_array, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (my_array[i] > 0)
		{
			return true;
			break;
		}
	}
	return false;
}

int* get_first_array(int* my_array, size_t size)
{
	my_array[get_index_of_minimum_positive_element(my_array, size)] = my_array[size - 1];
	return my_array;
}