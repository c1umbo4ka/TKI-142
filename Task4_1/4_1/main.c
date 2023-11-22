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
* @brief Функция для считывания значения с клавиатуры.
* @param message - сообщение пользователю.
* @remarks Экстренное завершение программы, в случае неправильного ввода.
* @return Значение с клавиатуры.
*/
int get_value(const char* message);

/**
* @brief Функция для проверки длинны массива.
* @param int_size - длинна массива.
* @remarks Экстренное завершение программы, в случае неправильной длинны массива.
*/
void true_size(int int_size);

/**
* @brief Функция для проверки массива.
* @param my_array - массив.
* @remarks Экстренное завершение программы, в случае несуществования массива.
*/
void true_array(int* my_array);

/**
* @brief Функция для считывания элементов массива с клавиатуры.
* @param size - длинна массива.
* @param my_array - массив.
*/
void get_manual_input_array(int* my_array, const size_t size, const int minimum_limit, const int maximum_limit);

/**
* @brief Функция для заполнения массива случайными числами.
* @param size - длинна массива.
* @param my_array - массив.
*/
void get_random_input_array(int* my_array, const size_t size, const int minimum_limit, const int maximum_limit);

/**
* @brief Функция для печати массива.
* @param my_array - массив.
* @param size - длинна массива.
* @return Массив.
*/
void print_array(int* my_array, const size_t size);

/**
* @brief Функция для нахождения минимального элемента массива и замены среднего элемента на него.
* @param my_array - массив.
* @param size - длинна массива.
*/
int get_minimum_element(int* my_array, const size_t size);

/**
* @brief Функция вывода индексов элементов, значение которых больше предыдущего (начиная со второго).
* @param my_array - массив.
* @param size - длинна массива.
*/
void print_number_of_elements_that_more_than_previous(int* my_array, const size_t size);

/**
* @brief Функция для нахождения количества пар соседних элементов с разными знаками.
* @param my_array - массив.
* @param size - длинна массива.
* @return Возвращает истину в случае успеха.
*/
bool get_two_pair_with_same_sign(int* my_array, const size_t size);

/**
* @brief Функция проверки интервала массива на правильность.
* @param minimum_limit - минимальный возможный элемент массива.
* @param maximum_limit - максимальный возможный элемент массива.
*/
void check_segment(const int minimum_limit, const int maximum_limit);

/**
* @brief Точка входа в программу.
* @return \c 0 в случае успеха, иначе \c 1.
*/
int main()
{
	setlocale(LC_ALL, "RU");

	const int int_size = get_value("Введите размер массива (обязательно нечётное число): ");
	true_size(int_size);
	size_t size = (size_t)(int_size);

	const int minimum_limit = get_value("Введите минимум массива: ");
	const int maximum_limit = get_value("Введите максимум массива: ");
	check_segment(minimum_limit, maximum_limit);

	int* my_array = (int*)malloc(size * sizeof(int));

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

	my_array[size / 2] = get_minimum_element(my_array, size);
	puts("Ответ на первое задание:");
	print_array(my_array, size);


	printf_s("Ответ на второе задание:\n");
	print_number_of_elements_that_more_than_previous(my_array, size);

	printf_s("Ответ на третье задание: ");
	if (get_two_pair_with_same_sign(my_array, size))
	{
		printf("%s", "минимум две пары соседних элементов с одинаковыми знаками в этом массиве есть.");
	}
	else
	{
		printf("%s", "количество пар соседних элементов с одинаковыми знаками в этом массиве меньше двух.");
	}

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
	if (int_size <= 0 || int_size % 2 == 0)
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

void get_manual_input_array(int* my_array, const size_t size, const int minimum_limit, const int maximum_limit)
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

void get_random_input_array(int* my_array, const size_t size, const int minimum_limit, const int maximum_limit)
{
	unsigned int ttime = time(NULL);
	srand(ttime);
	for (size_t i = 0; i < size; i++)
	{
		my_array[i] = minimum_limit + rand() % (maximum_limit - minimum_limit + 1);
	}
}

int get_minimum_element(int* my_array, const size_t size)
{
	int minimum_element = my_array[0];
	for (size_t i = 1; i < size; i++)
	{
		if (minimum_element > my_array[i])
		{
			minimum_element = my_array[i];
		}
	}
	return minimum_element;
}

void print_number_of_elements_that_more_than_previous(int* my_array, const size_t size)
{
	for (size_t i = 1; i < size; i++)
	{
		if (my_array[i] > my_array[i - 1])
		{
			printf_s("%Iu %d\n", i, my_array[i]);
		}
	}
}

bool get_two_pair_with_same_sign(int* my_array, const size_t size)
{
	int quantity = 0;
	for (size_t i = 1; i < size; i++)
	{
		if ((my_array[i] * my_array[i - 1] > 0))
		{
			quantity += 1;
		}
	}
	if (quantity >= 2)
	{
		return true;
	}
	return false;
}


void print_array(int* my_array, const size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		printf("%Iu %d\n", i, my_array[i]);
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