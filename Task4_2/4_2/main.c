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
void get_manual_input_array(int* my_array, size_t size, const int minimum_limit, const int maximum_limit);

/**
* @brief Функция для заполнения массива случайными числами.
* @param size - длина массива.
* @param my_array - массив.
*/
void get_random_input_array(int* my_array, size_t size, const int minimum_limit, const int maximum_limit);

/**
* @brief Функция для печати массива.
* @param my_array - массив.
* @param size - длина массива.
*/
void print_array(int* my_array, size_t size);

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
* @param my_array - старый массив.
* @param new_array - новый массив.
* @remarks Экстренное завершение программы, в случае несуществования массива.
*/
void true_array(int* my_array, int* new_array);

/**
* @brief Функция проверки интервала массива на правильность.
* @param minimum_limit - минимальный возможный элемент массива.
* @param maximum_limit - максимальный возможный элемент массива.
*/
void check_segment(const int minimum_limit, const int maximum_limit);

/**
* @brief Функция для нахождения индекса минимального положительного элемента массива.
* @param my_array - массив.
* @param size - длина массива.
* @return Индекс минимального положительного элемента массива.
*/
int get_index_of_minimum_positive_element(int* my_array, size_t size);

/**
* @brief Функция для нахождения первого положительного элемента массива.
* @param my_array - массив.
* @param size - длина массива.
* @return Максимальный элемент массива.
*/
int get_first_positive_element(int* my_array, size_t size);

/**
* @brief Функция для печати массива.
* @param my_array - массив.
* @param size - длина массива.
* @param new_size - новая длина массива.
*/
void print_modified_array(int* my_array, size_t new_size);

/**
* @brief Функция для нахождения новой длины массива.
* @param my_array - массив.
* @param size - длина массива.
* @return Новая длина массива.
*/
int get_new_size(int* my_array, size_t size);

/**
* @brief Функция для заполнения нового массива.
* @param my_array - старый массив.
* @param new_size - новая длина массива.
* @paran new_array - новый массив.
*/
void get_new_array(int* my_array, size_t new_size, int* new_array);

/**
* @brief Функция для печати нового массива.
* @param new_array - новый массив.
* @param new_size - новая длина массива.
*/
void print_new_array(int* new_array, size_t new_size);

/**
* @brief Функция для получения изменённого массива.
* @param my_array - старый массив.
* @param size - старая длина массива.
* @param new_size - новая длина массива.
* @return Изменённый массив.
*/
int get_modified_array(int* my_array, size_t size, size_t new_size);

int main()
{
	setlocale(LC_ALL, "RU");

	int int_size = get_value("Введите размер массива: ");
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

	my_array[get_index_of_minimum_positive_element(my_array, size)] = my_array[size - 1];
	puts("Ответ на первое задание:");
	print_array(my_array, size);

	size_t new_size = get_new_size(my_array, size);

	get_modified_array(my_array, size, new_size);
	puts("Ответ на второе задание:");
	print_modified_array(my_array, new_size);

	int* new_array = (int*)malloc(new_size * sizeof(int));
	get_new_array(my_array, new_size, new_array);
	puts("Ответ на третье задание:");
	print_new_array(new_array, new_size);
	
	true_array(my_array, new_array);
	free(my_array, new_array);
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

void true_array(int* my_array, int* new_array)
{
	if (my_array == NULL || new_array == NULL)
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

void print_array(int* my_array, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		printf("%Iu %d\n", i, my_array[i]);
	}
}

int get_index_of_minimum_positive_element(int* my_array, size_t size)
{
	int minimum_positive_element = my_array[get_first_positive_element(my_array, size)];
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

int get_first_positive_element(int* my_array, size_t size)
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

void print_modified_array(int* my_array, size_t new_size)
{
	for (size_t i = 0; i < new_size; i++)
	{
		printf("%Iu %d\n", i, my_array[i]);
	}
}

void get_new_array(int* my_array, size_t new_size, int* new_array)
{
	for (size_t i = 0; i < new_size; i++)
	{
		if ((i % 2) == 0)
		{
			new_array[i] = my_array[i] + i;
		}
		else
		{
			new_array[i] = my_array[i] - i;
		}
	}
}

int get_new_size(int* my_array, size_t size)
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

void print_new_array(int* new_array, size_t new_size)
{
	for (size_t i = 0; i < new_size; i++)
	{
		printf("%Iu %d\n", i, new_array[i]);
	}
}

int get_modified_array(int* my_array, size_t size, size_t new_size)
{
	for (int i = 0; i < size; i++)
	{
		if (my_array[i] % 10 % 2 != 0 && my_array[i] % 3 == 0)
		{
			for (int j = i; j < size - 1; j++)
			{
				my_array[j] = my_array[j + 1];
			}
			my_array[size - 1] = 0;
		}
	}
	my_array = (int*)realloc(my_array, new_size * sizeof(int));
}