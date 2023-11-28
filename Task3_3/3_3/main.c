#include <stdio.h>
#include <locale.h>
#include <errno.h>
#include <math.h>
#include <stdlib.h>

/**
* @brief ������� ��� ���������� ������������� ����� ����.
* @param x �������� �������, ���������������� �����.
* @param k ������ ����� ����.
* @return �������� ������������� �����.
*/
double get_recurrent(double x, double k);

/**
* @brief ������� ��� ���������� ����� ����.
* @param x ���������� �������.
* @param e ����������� ����������.
* @return �������� 3 � ������� x.
*/
double get_series_sum(double x, double e);

/**
* @brief ����� ����� � ���������.
* @return ���������� 0 � ������ ������.
*/
int main()
{
	setlocale(LC_ALL, "RU");

	const double a = 0.1;
	const double b = 1;
	const double h = 0.01;
	const double e = pow(10, -4);

	double x = a;
	while (x <= b + e)
	{
		double function = (exp(x) + exp(-x)) / 2;
		double series = get_series_sum(x, e);

		printf_s("%.2lf | %.15lf | %.15lf \n", x, function, series);

		x += h;
	}

	return EXIT_SUCCESS;
}


double get_series_sum(double x, double e)
{
	double previous = 0.0;
	double current = 1.0;
	double sum = current;
	double k = 1.0;

	while (fabs(previous - current) >= e)
	{
		previous = current;
		current = previous * get_recurrent(x, k);
		sum += current;
		k++;
	}

	return sum;
}

double get_recurrent(double x, double k)
{
	return pow(x, 2) / (4 * pow(k, 2) + 6 * k + 2);
}