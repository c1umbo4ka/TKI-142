#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <errno.h>
#include <locale.h>
#include <stdio.h>

/**
* @brief ���������������� ����.
*/
enum user_input
{
	/**
	* @brief �������.
	*/
	RADIANS = 1,
	/**
	* @brief �������.
	*/
	DEGREES = 2
};

/**
* @brief �������� ����� ��������.
* @remarks ���������� ���������� ���������, � ������ ������������� �����.
* @return ����� ��������.
*/
int get_choice();

/**
* @brief ������� ��� �������� ����� ������ ��� ��������.
* @remarks ���������� ���������� ���������, � ������ ������������� �����.
* @return ���������� ������ ��� ��������.
*/
double get_value();

/**
* @brief ������� ��� �������� ������.
* @return ���������� ������.
*/
double get_radians();

/**
* @brief ������� ��� �������� ��������.
* @param radians - �������� ���������� ������.
* @return ���������� ��������.
*/
double calculate_degrees(double radians);

/**
* @brief ������� ��� �������� ��������.
* @return ���������� ��������.
*/
double get_degrees();

/**
* @brief ������� ��� �������� ������.
* @param degrees - �������� ���������� ��������.
* @return ���������� ������.
*/
double calculate_radians(double degrees);

/**
* @brief ����� ����� � ���������.
* @return \c 0 � ������ ������, ����� \c 1.
*/
int main()
{
	setlocale(LC_ALL, "RU");

	puts("������� ����� ��������������� �������:\n");
	printf_s("%d - ��� ���������� ��������\n", RADIANS);
	printf_s("%d - ��� ���������� ������\n", DEGREES);

	int choice = get_choice();

	enum UserInput user_choice = (enum user_input)choice;

	switch (user_choice)
	{
	case RADIANS:
	{
		double radians = get_radians();
		double degrees = calculate_degrees(radians);
		printf_s("%lf ������ = %lf�", radians, degrees);
		break;
	}
	case DEGREES:
	{
		double degrees = get_degrees();
		double radians = calculate_radians(degrees);
		printf_s("%lf� = %lf ������", degrees, radians);
		break;
	}
	default:
	{
		errno = EDOM;
		perror("������ �����");
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
		perror("������ �����");
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
		perror("������� ������������ ��������");
		abort();
	}
	return value;
}

double get_radians()
{
	puts("������� ���������� ������:");
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
	puts("������� ���������� ��������:");
	double degrees = get_value();
	return degrees;
}

double calculate_radians(double degrees)
{
	const double to_radians = 180 * M_PI;
	return degrees * to_radians;
}