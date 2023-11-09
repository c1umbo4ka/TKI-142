#include <stdio.h>

/**
* @brief Функция вывода дня недели и проверки ввода.
* @param number Аргумент функции.
* @return Возвращает название дня недели в случае успеха.
*/
int getDay(int number);

/**
* @brief Функция вывода месяца и проверки ввода.
* @param number Аргумент функции.
* @return Возвращает название дня недели в случае успеха.
*/
int getMonth(int number);

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

enum months 
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
	int number;
	printf("Enter a number to find the day of the week and month: ");
	scanf_s("%d", &number);
	getDay(number);
	getMonth(number);
	return 0;
}

int getDay(int number)
{
	if (number >= 1 && number <= 7)
	{
		printf("%s", "Day of the week: ");
		switch (number)
		{
			case Monday:
			{
				printf("%s\n", "Monday");
				break;
			}
			case Tuesday:
			{
				printf("%s\n", "Tuesday");
				break;
			}
			case Wednesday:
			{
				printf("%s\n", "Wensday");
				break;
			}
			case Thursday:
			{
				printf("%s\n", "Thursday");
				break;
			}
			case Friday:
			{
				printf("%s\n", "Friday");
				break;
			}
			case Saturday:
			{
				printf("%s\n", "Saturday");
				break;
			}
			case Sunday:
			{
				printf("%s\n", "Sunday");
				break;
			}
		}
	}
	else
	{
		printf("Invalid day of the week number.\n");
	}
	
}

int getMonth(int number)
{
	if (number >= 1 && number <= 12)
	{
		printf("%s", "Month: ");
		switch (number)
		{
			case January:
			{
				printf("%s", "January");
				break;
			}
			case February:
			{
				printf("%s", "February");
				break;
			}
			case March:
			{
				printf("%s", "March");
				break;
			}
			case April:
			{
				printf("%s", "April");
				break;
			}
			case May:
			{
				printf("%s", "May");
				break;
			}
			case June:
			{
				printf("%s", "June");
				break;
			}
			case July:
			{
				printf("%s", "July");
				break;
			}
			case August:
			{
				printf("%s", "August");
				break;
			}
			case September:
			{
				printf("%s", "September");
				break;
			}
			case October:
			{
				printf("%s", "October");
				break;
			}
			case November:
			{
				printf("%s", "November");
				break;
			}
			case December:
			{
				printf("%s", "December");
				break;
			}
		}
	}
	else {
		printf("Invalid month number.\n");
	}
}