#include<stdio.h>
#include<string>
#include"DateClass.h"
using namespace std;

static char *WEEK_NAME[] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday " };

int main(void)
{
	int year = 2014, month = 4, day = 26;
	Date date(year, month, day);
	date.displayDate();
	date.showWeek();	
	while (getchar()!='\n');
}
