#include <stdio.h>
#include <locale.h>
#include <errno.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>
#include <time.h>

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
void get_manual_input_array(int* my_array, const size_t size);

/**
* @brief Функция для заполнения массива случайными числами.
* @param size - длинна массива.
* @param my_array - массив.
*/
void get_random_input_array(int* my_array, const size_t size);

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
* @return индекс элементов.
*/
size_t get_number_of_elements_that_more_than_previous(int* my_array, const size_t size);

/**
* @brief Функция для нахождения количества соседних элементов с разными знаками.
* @param my_array - массив.
* @param size - длинна массива.
* @return Успех, если таких пар больше двух.
*/
size_t get_two_pair_with_same_sign(int* my_array, const size_t size);

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
		get_manual_input_array(my_array, size);
		break;
	}
	case RANDOM:
	{
		get_random_input_array(my_array, size);
		break;
	}
	default:
	{
		errno = EDOM;
		perror("Ошибка ввода");
		return EXIT_FAILURE;
	}
	}

	my_array[size/2] = get_minimum_element(my_array, size);
	puts("Ответ на первое задание:");
	print_array(my_array, size);


	printf_s("Ответ на второе задание:\n");
	get_number_of_elements_that_more_than_previous(my_array, size);

	printf_s("Ответ на третье задание: %s", get_two_pair_with_same_sign(my_array,size));
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

void get_manual_input_array(int* my_array, const size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		const int minimum_limit = -20;
		const int maximum_limit = 40;
		int c = get_value("Введите число от -20 до 40: ");
		if (c < minimum_limit || c > maximum_limit)
		{
			errno = EIO;
			perror("Ошибка ввода");
			abort();
		}
		my_array[i] = c;
	}
}

void get_random_input_array(int* my_array, const size_t size)
{
	unsigned int ttime = time(NULL);
	srand(ttime);
	for (size_t i = 0; i < size; i++)
	{
		my_array[i] = -20 + rand() % 61;
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

size_t get_number_of_elements_that_more_than_previous(int* my_array, const size_t size)
{
	for (size_t i = 1; i < size; i++)
	{
		if (my_array[i] > my_array[i - 1])
		{
			printf_s("%Iu %d\n", i, my_array[i]);
		}
	}
}

size_t get_two_pair_with_same_sign(int* my_array, const size_t size)
{
	int quantity = 0;
	for (size_t i = 1; i < size; i++)
	{
		if ((my_array[i] > 0 && my_array[i - 1] > 0) || (my_array[i] < 0 && my_array[i - 1] < 0))
		{
			quantity += 1;
		}
	}
	if (quantity >= 2)
	{
		return "минимум две пары соседних элементов с одинаковыми знаками в этом массиве есть.";
	}
	return "количество пар соседних элементов с одинаковыми знаками в этом массиве меньше двух.";
}


void print_array(int* my_array, const size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		printf("%Iu %d\n", i, my_array[i]);
	}
}