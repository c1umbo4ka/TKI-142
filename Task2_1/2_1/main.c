#include <stdio.h>

int getDay(int number);

int getMonth(int number);

enum DaysOfWeek 
{
	Monday = 1,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};

enum Months 
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
		printf("Day of the week: %s\n",
			number == Monday ? "Monday" :
			number == Tuesday ? "Tuesday" :
			number == Wednesday ? "Wednesday" :
			number == Thursday ? "Thursday" :
			number == Friday ? "Friday" :
			number == Saturday ? "Saturday" :
			"Sunday");
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
		printf("Month: %s\n",
			number == January ? "January" :
			number == February ? "February" :
			number == March ? "March" :
			number == April ? "April" :
			number == May ? "May" :
			number == June ? "June" :
			number == July ? "July" :
			number == August ? "August" :
			number == September ? "September" :
			number == October ? "October" :
			number == November ? "November" :
			"December");
	}
	else {
		printf("Invalid month number.\n");
	}
}