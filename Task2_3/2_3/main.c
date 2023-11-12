#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

/**
* @brief Функция проверки правильности ввода.
* @return Возвращает название фигуры в случае правильности ввода.
*/
char get_figure();

enum figure
{
	square = 1,
	triangle,
	rhombus,
	rectangle,
	trapezoid,
	circle,
	parallelogram
};

/**
* @brief Точка входа в программу.
* @return Возвращает 0 в случае успеха.
*/
int main()
{
	printf("Enter a name of the shape: ");
	char input_figure = get_figure();
	switch (input_figure)
	{
		case square:
		{
			printf("%s", "S = a * a\na - side");
			break;
		}
		case triangle:
		{
			printf("%s", "S = 1/2 * a * h\na - base\nh - height drawn to this base");
			break;
		}
		case rhombus:
		{
			printf("%s", "S = 1/2 * d1 * d2\nd1 - first diagonal\nd2 - second diagonal");
			break;
		}
		case rectangle:
		{
			printf("%s", "S = a * b\na and b - neighboring sides");
			break;
		}
		case trapezoid:
		{
			printf("%s", "S = (a + b)/2 * h\na and b - bases\nh - height");
			break;
		}
		case circle:
		{
			printf("%s", "S = π * R * R\nπ - Pi\nR - radius");
			break;
		}
		case parallelogram:
		{
			printf("%s", "S = a * h\na - base\nh - height drawn to this base");
			break;
		}
		default:
		{
			printf("%s", "S = 1/2 * d1 * d2 * sin(α)\nd1 - first diagonal\nd2 - second diagonal\nα - acute angle between diagonals");
			break;
		}
	}
	return 0;
}

char get_figure()
{
	char input;
	int result = scanf_s("%s", &input);
	if (result != 1)
	{
		errno = EIO;
		perror("Invalid figure entered!!!");
		abort();
	}
	return input;
}