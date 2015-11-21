#include"CreditCardAcct.h"
#include<iostream>
using namespace std;

CreditCardAcct::CreditCardAcct(string accountName, int accountBalance, Date& date)
{
	password = 0;
	account_id = ++allAccounts;
	account_name = accountName;
	creditLimit = -100;
	account_balance = 0;
	if (accountBalance>0)
		deposite(accountBalance, date);
	printf("Contructing CreditCardAcct object\n");
}
CreditCardAcct::CreditCardAcct(CreditCardAcct& account) throw(bad_alloc) try
{
	record = account.record;//throw(bad_alloc)
	password = account.password;
	account_id = account.account_id;
	account_name = account.account_name;
	account_balance = account.account_balance;	
}
catch (bad_alloc e) {
	cout << e.what() << endl;
}
CreditCardAcct::CreditCardAcct()
{
	password = 0;
	account_id = ++allAccounts;
	account_name = "";
	account_balance = 0;
}
CreditCardAcct::~CreditCardAcct()
{
	password = 0;
	account_id = 0;
	account_name = "";
	account_balance = 0;
	printf("Destructing CreditCardAcct object\n");
}
int CreditCardAcct::getBalance()
{
	return account_balance;
}
void CreditCardAcct::deposite(int amount, Date& date) throw(bad_alloc, invalid_argument)
{
	if (amount <= 0)
		throw invalid_argument("invalid argument for CreditCardAcct::deposite");
	RcdItem item;
	item.add = 1;
	item.amount = amount;
	item.date = date;
	record.push_back(item);
	account_balance += amount;
}
void CreditCardAcct::withdraw(int amount, Date& date) throw(bad_alloc,invalid_argument)
{
	if (amount <= 0)
		throw invalid_argument("invalid argument for CreditCardAcct::deposite");
	if (account_balance-amount<creditLimit)
	{
		cout << "not enough money" << endl;
		return;
	}
	RcdItem item;
	item.add = 0;
	item.amount = amount;
	item.date = date;
	record.push_back(item);
	account_balance -= amount;
}

void CreditCardAcct::printAllRecd()
{
	for (list<RcdItem>::iterator iter = record.begin();iter != record.end();iter++)
		PrintItem(*iter);
}
void CreditCardAcct::searchRecd(Date & date1, Date & date2) throw(invalid_argument)
{
	if (date1 > date2)
	{
		printf("date is invalid\n");
		throw invalid_argument("invalid argument for CreditCardAcct::searchRecd");
	}
	RcdItem item1, item2;
	item1.date = date1;
	item2.date = date2;
	for (list<RcdItem>::iterator iter = record.begin();iter != record.end()&&(*iter)>=item1&&(*iter)<=item2;iter++)
		PrintItem(*iter);
}
Account& CreditCardAcct::operator=(Account& account) throw(bad_alloc)
{

	record = account.getRecord();//deep copy,throw(bad_alloc)
	password = account.getPassword();
	account_id = account.getNumber();
	account_name = account.getName();
	account_balance = account.getBalance();	
	return *this;
}


