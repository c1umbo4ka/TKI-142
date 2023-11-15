#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

/**
* @brief Функция вывода дня недели и проверки ввода.
* @param number Аргумент функции.
* @return Возвращает название дня недели в случае успеха.
*/
int getDay(enum day day);

/**
* @brief Функция вывода месяца и проверки ввода.
* @param number Аргумент функции.
* @return Возвращает название месяца в случае успеха.
*/
int getMonth(enum month month);

enum choice
{
	Day = 1,
	Month = 2
};

enum day
{
	Monday = 1,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};

enum month
{
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};

/**
* @brief Точка входа в программу.
* @return Возвращает 0 в случае успеха.
*/
int main()
{
	puts("Enter the number corresponding to the task:\n");
	printf_s("%d - to display the day of the week\n", Day);
	printf_s("%d - to display the month\n", Month);
	int input = get_value();
	enum UserInput user_choice = (enum choice)input;
	switch (user_choice)
	{
		case Day:
		{
			printf_s("%s", "Enter a number to find the day of the week: ");
			int number = get_value();
			enum UserInput day = (enum choice)number;
			getDay(day);
			break;
		}
		case Month:
		{
			puts("Enter a number to find month: ");
			int number = get_value();
			enum UserInput month = (enum choice)number;
			getMonth(month);
			break;
		}
		default:
		{
			puts("Invalid choice.");
			break;
		}
	}
	return 0;
}

int getDay(enum day day)
{
	switch (day)
	{
		case Monday:
		{
			printf_s("%s", "Day of the week: ");
			printf("%s\n", "Monday");
			break;
		}
		case Tuesday:
		{
			printf_s("%s", "Day of the week: ");
			printf("%s\n", "Tuesday");
			break;
		}
		case Wednesday:
		{
			printf_s("%s", "Day of the week: ");
			printf("%s\n", "Wensday");
			break;
		}
		case Thursday:
		{
			printf_s("%s", "Day of the week: ");
			printf("%s\n", "Thursday");
			break;
		}
		case Friday:
		{
			printf_s("%s", "Day of the week: ");
			printf("%s\n", "Friday");
			break;
		}
		case Saturday:
		{
			printf_s("%s", "Day of the week: ");
			printf("%s\n", "Saturday");
			break;
		}
		case Sunday:
		{
			printf_s("%s", "Day of the week: ");
			printf("%s\n", "Sunday");
			break;
		}
		default:
		{
			printf_s("%s", "Invalid day of the week number.");
			break;
		}
	}
}

int getMonth(enum month month)
{
	
	switch (month)
	{
		case January:
		{
			printf_s("%s", "Month: ");
			printf("%s\n", "January");
			break;
		}
		case February:
		{
			printf_s("%s", "Month: ");
			printf("%s\n", "February");
			break;
		}
		case March:
		{
			printf_s("%s", "Month: ");
			printf("%s\n", "March");
			break;
		}
		case April:
		{
			printf_s("%s", "Month: ");
			printf("%s\n", "April");
			break;
		}
		case May:
		{
			printf_s("%s", "Month: ");
			printf("%s\n", "May");
			break;
		}
		case June:
		{
			printf_s("%s", "Month: ");
			printf("%s\n", "June");
			break;
		}
		case July:
		{
			printf_s("%s", "Month: ");
			printf("%s\n", "July");
			break;
		}
		case August:
		{
			printf_s("%s", "Month: ");
			printf("%s\n", "August");
			break;
		}
		case September:
		{
			printf_s("%s", "Month: ");
			printf("%s\n", "September");
			break;
		}
		case October:
		{
			printf_s("%s", "Month: ");
			printf("%s\n", "October");
			break;
		}
		case November:
		{
			printf_s("%s", "Month: ");
			printf("%s\n", "November");
			break;
		}
		case December:
		{
			printf_s("%s", "Month: ");
			printf("%s\n", "December");
			break;
		}
		default:
		{
			printf_s("%s", "Invalid mounth number.");
			break;
		}
	}
}

int get_value()
{
	int value;
	int result = scanf_s("%d", &value);
	if (result != 1)
	{
		errno = EIO;
		perror("Invalid value entered!!!");
		abort();
	}
	return value;
}