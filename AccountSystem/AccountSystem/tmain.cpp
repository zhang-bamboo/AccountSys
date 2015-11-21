#include"List.h"
#include<fstream>
#include"CreditCardAcct.h"
#include"DemandAcct.h"
#include"DateClass.h"
using namespace std;
int main()
{
	Date date1;
	Date date2;
	date1.setDate(2015, 10, 10);
	date2.setDate(2015, 9, 9);

	CreditCardAcct credit1("zhang", 100, date1);
	CreditCardAcct credit2("long", 0, date2);

	credit2 = credit1;
	while (1);
}
