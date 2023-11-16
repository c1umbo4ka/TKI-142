#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

/**
* @brief Функция проверки правильности ввода.
* @return Возвращает значение в случае правильности ввода.
*/
int get_figure();

/**
* @brief Функция вывода формулы площади.
*/
void get_formula(enum UserInput user_choice);

enum figure
{
	square = 1,
	triangle,
	rhombus,
	rectangle,
	trapezoid,
	circle,
	parallelogram,
	arbitrary
};

/**
* @brief Точка входа в программу.
* @return Возвращает 0 в случае успеха.
*/
int main()
{
	puts("Enter the number corresponding to the task:\n");
	printf_s("%d - to display area formula of the square\n", square);
	printf_s("%d - to display area formula of the triangle\n", triangle);
	printf_s("%d - to display area formula of the rhombus\n", rhombus);
	printf_s("%d - to display area formula of the rectangle\n", rectangle);
	printf_s("%d - to display area formula of the trapezoid\n", trapezoid);
	printf_s("%d - to display area formula of the circle\n", circle);
	printf_s("%d - to display area formula of the parallelogram\n", parallelogram);
	printf_s("%d - to display area formula of the arbitrary\n", arbitrary);
	char input = get_figure();
	enum UserInput user_choice = (enum figure)input;
	get_formula(user_choice);
	return 0;
}

void get_formula(enum UserInput user_choice)
{
	switch (user_choice)
	{
		case square:
		{
			puts("S = a * a");
			puts("a - side");
			break;
		}
		case triangle:
		{
			puts("S = (1/2) * a * h");
			puts("a - base");
			puts("h - height");
			break;
		}
		case rhombus:
		{
			puts("S = (1/2) * d1 * d2");
			puts("d1 and d2 - diagonals");
			break;
		}
		case rectangle:
		{
			puts("S = a * b");
			puts("a and b - neighboring sides");
			break;
		}
		case trapezoid:
		{
			puts("S = ((a + b)/2) * h");
			puts("a and b - bases");
			puts("h - height");
			break;
		}
		case circle:
		{
			puts("S = π * R * R");
			puts("R - radius");
			break;
		}
		case parallelogram:
		{
			puts("S = a * h");
			puts("a - base");
			puts("h - height");
			break;
		}
		case arbitrary:
		{
			puts("S = (1/2) * d1 * d2 * sin(α)");
			puts("d1 and d2 - diagonals");
			puts("α - angle between them");
			break;
		}
		default:
		{
			puts("Invalid number entered.");
			break;
		}
	}
}

int get_figure()
{
	int input;
	int result = scanf_s("%d", &input);
	if (result != 1)
	{
		errno = EIO;
		perror("Invalid figure entered!!!");
		abort();
	}
	return input;
}