#include <stdio.h>
#include <locale.h>
#include <errno.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
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
* @brief Функция для проверки длинны или ширины массива.
* @param int_size - количество строк или столбцов массива.
* @remarks Экстренное завершение программы, в случае неправильной длинны или ширины массива.
*/
void is_size(int int_size);

/**
* @brief Функция для выделения памяти для массива.
* @param lines - количество строк массива.
* @param columns - количество столбцов массива.
* @return Указатель на выделенную для массива память.
*/
int** allocating_memory_for_array(const size_t lines, const size_t columns);

/**
* @brief Функция для проверки массива.
* @param my_array - массив.
* @remarks Экстренное завершение программы, если место для массива не выделено.
*/
void is_array(int** my_array);

/**
* @brief Функция для считывания элементов массива с клавиатуры.
* @param my_array - массив.
* @param lines - количество строк массива.
* @param columns - количество столбцов массива.
* @param minimum_limit - минимальный элемент массива.
* @param maximum_limit - максимальный элемент массива.
*/
void get_manual_input_array(int** my_array, const size_t lines, const size_t columns, const int minimum_limit, const int maximum_limit);

/**
* @brief Функция для заполнения массива случайными числами.
* @param my_array - массив.
* @param lines - количество строк массива.
* @param columns - количество столбцов массива.
* @param minimum_limit - минимальный элемент массива.
* @param maximum_limit - максимальный элемент массива.
*/
void get_random_input_array(int** my_array, const size_t lines, const size_t columns, const int minimum_limit, const int maximum_limit);

/**
* @brief Функция для печати массива.
* @param my_array - массив.
* @param lines - количество строк массива.
* @param columns - количество столбцов массива.
*/
void print_array(int** my_array, size_t lines, size_t columns);

/**
* @brief Функция для замены максимальных элементов каждого столбца нулем.
* @param my_array - массив.
* @param lines - количество строк массива.
* @param columns - количество столбцов массива.
* @return Массив с заменёнными числами.
*/
int** array_for_first_task(int** my_array, size_t lines, size_t columns);

/**
* @brief Функция для создания и заполнения массива, в котором после строк, содержащих минимальный элемент, идут строки с порядковыми числами.
* @param my_array - исходный массив.
* @param lines - количество строк массива.
* @param columns - количество столбцов массива.
* @param maximum_element - максимальный по модулю элемент массива.
* @param new_lines - количество строк массива, в котором будут содержаться строки с порядковыми числами.
* @return Массив, содержащий строки с элементами первой строки исходного массива.
*/
int** array_for_second_task(int** my_array, size_t lines, size_t columns, int maximum_element, size_t new_lines);

/**
* @brief Функция для нахождения максимального по модулю элемента массива.
* @param my_array - массив.
* @param lines - количество строк массива.
* @param columns - количество столбцов массива.
* @return Максимальный по модулю элемент массива.
*/
int get_maximum_modulus_element(int** my_array, size_t lines, size_t columns);

/**
* @brief Функция для определения содержит строка максимальный по модулю элемент или нет.
* @param my_array - строка массива.
* @param columns - количество столбцов массива.
* @param maximum_element - максимальный по модулю элемент массива.
* @return true если строка содержит минимальный элемент массива, иначе false.
*/
bool line_have_maximum_element(int* my_array, size_t columns, int maximum_element);

/**
* @brief Функция для подсчёта количества строк массива с минимальным элементом.
* @param my_array - массив.
* @param lines - количество строк массива.
* @param columns - количество столбцов массива.
* @param maximum_element - максимальный по модулю элемент массива.
* @return Количество строк массива с максимальным по модулю элементо массива.
*/
size_t number_new_lines(int** my_array, size_t lines, size_t columns, int maximum_element);

/**
* @brief Функция для создания массива с первой строкой исходного массива.
* @param my_array - исходный массив.
* @param columns - количество столбцов массива.
*/
int* get_array_with_first_line(int** my_array, size_t columns);

/**
* @brief Функция для проверки отрезка массива.
* @param minimum_limit - минимальный элемент массива.
* @param maximum_limit - максимальный элемент массива.
*/
void check_segment(const int minimum_limit, const int maximum_limit);

/**
* @brief Функция для создания и заполнения массива с максимальными жлементами каждого столбца исходного массива.
* @param my_array - исходный массив.
* @param lines - количество строк массива.
* @param columns - количество столбцов массива.
*/
int* get_array_with_maximum_elements_in_columns(int** my_array, size_t lines, size_t columns);

/**
* @brief Точка входа в программу.
* @return Возвращает 0 в случае успеха.
*/
int main()
{
	setlocale(LC_ALL, "RU");

	int int_columns = get_value("Введите количество столбцов массива: ");
	is_size(int_columns);
	size_t columns = (size_t)(int_columns);
	
	int int_lines = get_value("Введите количество строк массива: ");
	is_size(int_lines);
	size_t lines = (size_t)(int_lines);

	const int minimum_limit = get_value("Введите минимум массива: ");
	const int maximum_limit = get_value("Введите максимум массива: ");
	check_segment(minimum_limit, maximum_limit);

	int** my_array = allocating_memory_for_array(lines, columns);

	puts("Введите номер соответствующий способу, которым вы хотите ввести массив:");
	printf_s("%d - для заполнения массива с клавиатуры\n", MANUAL);
	printf_s("%d - для заполнения массива случайными числами\n", RANDOM);

	int choice = get_value("");

	enum array_input_choice user_input = (enum user_input)choice;

	switch (user_input)
	{
	case MANUAL:
	{
		get_manual_input_array(my_array, lines, columns, minimum_limit, maximum_limit);
		break;
	}
	case RANDOM:
	{
		get_random_input_array(my_array, lines, columns, minimum_limit, maximum_limit, minimum_limit, maximum_limit);
		break;
	}
	default:
	{
		errno = EDOM;
		perror("Ошибка ввода");
		return EXIT_FAILURE;
	}
	}
	puts("Исходный массив: ");
	print_array(my_array, lines, columns);

	puts("Ответ на первое задание: ");
	print_array(array_for_first_task(my_array, lines, columns), lines, columns);

	int maximum_element = get_maximum_modulus_element(my_array, lines, columns);
	size_t new_lines = lines + number_new_lines(my_array, lines, columns, maximum_element);
	puts("Ответ на второе задание: ");
	print_array(array_for_second_task(my_array, lines, columns, maximum_element, new_lines), new_lines, columns);

	is_array(my_array);

	for (size_t l = 0; l < lines; l++)
	{
		free(my_array[l]);
	}
	free(my_array);

	return EXIT_SUCCESS;
}

int get_value(const char* message)
{
	int value;
	printf("%s", message);
	int res = scanf_s("%d", &value);
	if (res != 1)
	{
		errno = EIO;
		perror("Ошибка ввода");
		abort();
	}
	return value;
}

void is_size(int int_size)
{
	if (int_size <= 0)
	{
		errno = EIO;
		perror("Ошибка ввода");
		abort();
	}
}

int** allocating_memory_for_array(const size_t lines, const size_t columns)
{
	int** my_array = (int**)malloc(sizeof(int*) * lines);

	for (size_t i = 0; i < lines; i++)
	{
		my_array[i] = (int*)malloc(sizeof(int) * columns);
	}

	is_array(my_array);

	return my_array;
}

void is_array(int** my_array)
{
	if (my_array == NULL)
	{
		errno = ENOMEM;
		perror("Отсутствует память для массива");
		abort();
	}
}

void get_manual_input_array(int** my_array, const size_t lines, const size_t columns, const int minimum_limit, const int maximum_limit)
{
	for (size_t l = 0; l < lines; l++)
	{
		for (size_t c = 0; c < columns; c++)
		{
			printf("Введите элемент a[%d][%d] от %d до %d: ", l, c, minimum_limit, maximum_limit);
			my_array[l][c] = get_value("");
			if (my_array[l][c] < minimum_limit || my_array[l][c] > maximum_limit)
			{
				errno = EIO;
				perror("Ошибка ввода");
				abort();
			}
		}
	}
}

void get_random_input_array(int** my_array, const size_t lines, const size_t columns, const int minimum_limit, const int maximum_limit)
{
	unsigned int ttime = (unsigned int)(time(NULL));
	srand(ttime);
	for (size_t l = 0; l < lines; l++)
	{
		for (size_t c = 0; c < columns; c++)
		{
			my_array[l][c] = minimum_limit + rand() % (maximum_limit - minimum_limit + 1);
		}
	}
}

void print_array(int** my_array, size_t lines, size_t columns)
{
	for (size_t l = 0; l < lines; l++)
	{
		for (size_t c = 0; c < columns; c++)
		{
			printf_s("%d\t", my_array[l][c]);
		}
		printf_s("\n");
	}
}

int** array_for_first_task(int** my_array, size_t lines, size_t columns)
{
	int* max_elements = get_array_with_maximum_elements_in_columns(my_array, lines, columns);
	int** new_array = allocating_memory_for_array(lines, columns);

	for (size_t c = 0; c < columns; c++)
	{
		for (size_t l = 0; l < lines; l++)
		{
			new_array[l][c] = my_array[l][c];

			if (my_array[l][c] == max_elements[c])
			{
				new_array[l][c] = 0;
			}
		}
	}

	return new_array;
}

int** array_for_second_task(int** my_array, size_t lines, size_t columns, int maximum_element, size_t new_lines)
{
	int** new_array = allocating_memory_for_array(new_lines, columns);
	int* array_with_first_line = get_array_with_first_line(my_array, columns);

	size_t new_line = 0;
	size_t old_line = 0;

	while (new_line < new_lines)
	{
		new_array[new_line] = my_array[old_line];

		if (line_have_maximum_element(new_array[new_line], columns, maximum_element))
		{
			new_line++;
			new_array[new_line] = array_with_first_line;
		}

		new_line++;
		old_line++;
	}

	return new_array;
}

int get_maximum_modulus_element(int** my_array, size_t lines, size_t columns)
{
	int max_element = abs(my_array[0][0]);

	for (size_t l = 0; l < lines; l++)
	{
		for (size_t c = 0; c < columns; c++)
		{
			if (abs(my_array[l][c]) > max_element)
			{
				max_element = abs(my_array[l][c]);
			}
		}
	}

	return max_element;
}

bool line_have_maximum_element(int* my_array, size_t columns, int maximum_element)
{
	for (size_t c = 0; c < columns; c++)
	{
		if (abs(my_array[c]) == maximum_element)
		{
			return true;
		}
	}

	return false;
}

size_t number_new_lines(int** my_array, size_t lines, size_t columns, int maximum_element)
{
	size_t numbers = 0;

	for (size_t l = 0; l < lines; l++)
	{
		if (line_have_maximum_element(my_array[l], columns, maximum_element))
		{
			numbers++;
		}
	}

	return numbers;
}

int* get_array_with_first_line(int** my_array, size_t columns)
{
	int* array = (int*)malloc(sizeof(int) * columns);

	if (array == NULL)
	{
		errno = ENOMEM;
		perror("Отсутствует память для массива");
		abort();
	}

	for (size_t c = 0; c < columns; c++)
	{
		array[c] = my_array[0][c];
	}

	return array;
}

void check_segment(const int minimum_limit, const int maximum_limit)
{
	if (minimum_limit > maximum_limit)
	{
		puts("Неверно введен интервал.");
		abort();
	}
}

int* get_array_with_maximum_elements_in_columns(int** my_array, size_t lines, size_t columns)
{
	int* max_elements = (int*)malloc(sizeof(int) * columns);

	for (size_t c = 0; c < columns; c++)
	{
		for (size_t l = 0; l < lines; l++)
		{
			if (my_array[l][c] > max_elements[c])
			{
				max_elements[c] = my_array[l][c];
			}
		}
	}
	return max_elements;
}