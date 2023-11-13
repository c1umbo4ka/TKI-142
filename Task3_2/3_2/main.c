#include <stdio.h>
#include <math.h>
#include <float.h>
#include <errno.h>
#include <stdlib.h>

int get_factorial(int end);

double get_sum(int end);

double get_value();

int main()
{
	printf("%s", "Insert end of the segment: ");
	int end = get_value();
	printf("Summary = %lf", get_sum(end));
	return 0;
}

int get_factorial(int end)
{
	int factorial = 0;
	for (int variable = 1; variable < end + 1; variable++)
		if (variable * 2 == 0 || 2 * variable == 1)
		{
			factorial = 1;
		}
		else
		{
			factorial = factorial * variable;
		}
	return factorial;
}

double get_sum(int end)
{
	double sum = 0;
	for (int variable = 1; variable < end + 1; variable++)
	{
		sum = sum + (1.0 / (get_factorial(end)));
	}
	return sum;
}

double get_value()
{
	int value;
	int result = scanf_s("%d", &value);
	if (result != 1 || value <= 0)
	{
		errno = EIO;
		perror("Invalid value entered!!!");
		abort();
	}
	return value;
}