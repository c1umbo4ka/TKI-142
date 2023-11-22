#include <stdio.h>
#include <locale.h>
#include <errno.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/**
* @brief ����� ���������� �������.
*/
enum array_input_choice
{
	/**
	* @brief ������ ������.
	*/
	MANUAL = 1,
	/**
	* @brief ���������� ������� ���������� �������.
	*/
	RANDOM = 2
};

/**
* @brief ������� ��� ���������� �������� � ����������.
* @param message - ��������� ������������.
* @remarks ���������� ���������� ���������, � ������ ������������� �����.
* @return �������� � ����������.
*/
int get_value(const char* message);

/**
* @brief ������� ��� �������� ������ �������.
* @param int_size - ������ �������.
* @remarks ���������� ���������� ���������, � ������ ������������ ������ �������.
*/
void true_size(int int_size);

/**
* @brief ������� ��� �������� �������.
* @param my_array - ������.
* @remarks ���������� ���������� ���������, � ������ ��������������� �������.
*/
void true_array(int* my_array);

/**
* @brief ������� ��� ���������� ��������� ������� � ����������.
* @param size - ������ �������.
* @param my_array - ������.
*/
void get_manual_input_array(int* my_array, const size_t size, const int minimum_limit, const int maximum_limit);

/**
* @brief ������� ��� ���������� ������� ���������� �������.
* @param size - ������ �������.
* @param my_array - ������.
*/
void get_random_input_array(int* my_array, const size_t size, const int minimum_limit, const int maximum_limit);

/**
* @brief ������� ��� ������ �������.
* @param my_array - ������.
* @param size - ������ �������.
* @return ������.
*/
void print_array(int* my_array, const size_t size);

/**
* @brief ������� ��� ���������� ������������ �������� ������� � ������ �������� �������� �� ����.
* @param my_array - ������.
* @param size - ������ �������.
*/
int get_minimum_element(int* my_array, const size_t size);

/**
* @brief ������� ������ �������� ���������, �������� ������� ������ ����������� (������� �� �������).
* @param my_array - ������.
* @param size - ������ �������.
*/
void print_number_of_elements_that_more_than_previous(int* my_array, const size_t size);

/**
* @brief ������� ��� ���������� ���������� ��� �������� ��������� � ������� �������.
* @param my_array - ������.
* @param size - ������ �������.
* @return ���������� ������ � ������ ������.
*/
bool get_two_pair_with_same_sign(int* my_array, const size_t size);

/**
* @brief ������� �������� ��������� ������� �� ������������.
* @param minimum_limit - ����������� ��������� ������� �������.
* @param maximum_limit - ������������ ��������� ������� �������.
*/
void check_segment(const int minimum_limit, const int maximum_limit);

/**
* @brief ����� ����� � ���������.
* @return \c 0 � ������ ������, ����� \c 1.
*/
int main()
{
	setlocale(LC_ALL, "RU");

	const int int_size = get_value("������� ������ ������� (����������� �������� �����): ");
	true_size(int_size);
	size_t size = (size_t)(int_size);

	const int minimum_limit = get_value("������� ������� �������: ");
	const int maximum_limit = get_value("������� �������� �������: ");
	check_segment(minimum_limit, maximum_limit);

	int* my_array = (int*)malloc(size * sizeof(int));

	puts("������� ����� ��������������� �������, ������� �� ������ ������ ������:\n");
	printf_s("%d - ��� ���������� ������� � ����������\n", MANUAL);
	printf_s("%d - ��� ���������� ������� ���������� �������\n", RANDOM);

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
		perror("������ �����");
		return EXIT_FAILURE;
	}
	}

	my_array[size / 2] = get_minimum_element(my_array, size);
	puts("����� �� ������ �������:");
	print_array(my_array, size);


	printf_s("����� �� ������ �������:\n");
	print_number_of_elements_that_more_than_previous(my_array, size);

	printf_s("����� �� ������ �������: ");
	if (get_two_pair_with_same_sign(my_array, size))
	{
		printf("%s", "������� ��� ���� �������� ��������� � ����������� ������� � ���� ������� ����.");
	}
	else
	{
		printf("%s", "���������� ��� �������� ��������� � ����������� ������� � ���� ������� ������ ����.");
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
		perror("������ �����");
		abort();
	}
	return value;
}

void true_size(int int_size)
{
	if (int_size <= 0 || int_size % 2 == 0)
	{
		errno = EIO;
		perror("������ �����");
		abort();
	}
}

void true_array(int* my_array)
{
	if (my_array == NULL)
	{
		errno = EIO;
		perror("������ �����");
		abort();
	}
}

void get_manual_input_array(int* my_array, const size_t size, const int minimum_limit, const int maximum_limit)
{
	for (size_t i = 0; i < size; i++)
	{
		printf("������� ����� �� %d �� %d: ", minimum_limit, maximum_limit);
		int c = get_value("");
		if (c < minimum_limit || c > maximum_limit)
		{
			errno = EIO;
			perror("������ �����");
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
		puts("������� ������ ��������.");
		abort();
	}
}