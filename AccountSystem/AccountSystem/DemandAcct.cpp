#include"DemandAcct.h"
#include<iostream>
using namespace std;

DemandAcct::DemandAcct(string accountName, int accountBalance,Date& date)
{
	password = 0;
	account_id = ++allAccounts;
	account_name=accountName;
	account_balance = 0;
	if (accountBalance>0)
		deposite(accountBalance, date);
	printf("Contructing DemandAcct object\n");
}
DemandAcct::DemandAcct(DemandAcct& account) throw(bad_alloc) try
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
DemandAcct::DemandAcct()
{
	password=0;
	account_id = ++allAccounts;
	account_name="";
	account_balance = 0;
	printf("Contructing DemandAcct object\n");
}
DemandAcct::~DemandAcct()
{
	password = 0;
	account_id = 0;
	account_name = "";
	account_balance = 0;
	printf("Destructing DemandAcct object\n");
}
int DemandAcct::getBalance()
{
	return account_balance;
}
void DemandAcct::deposite(int amount,Date& date) throw(bad_alloc, invalid_argument)
{
	if (amount <= 0)
		throw invalid_argument("invalid argument for CreditCardAcct::deposite");
	RcdItem item;
	item.add = 1;
	item.amount = amount;
	item.date = date;
	record.push_back(item);//bad_alloc
	account_balance += amount;
}
void DemandAcct::withdraw(int amount,Date& date) throw(bad_alloc, invalid_argument)
{
	if (amount <= 0)
		throw invalid_argument("invalid argument for CreditCardAcct::deposite");
	if (amount > account_balance)
	{
		cout<< "not enough money" << endl;
		return;
	}
	RcdItem item;
	item.add = 0;
	item.amount = amount;
	item.date = date;
	record.push_back(item);//bad_alloc
	account_balance -= amount;
}

void DemandAcct::printAllRecd()
{

	for (list<RcdItem>::iterator iter = record.begin();iter != record.end();iter++)
		PrintItem(*iter);
}
void DemandAcct::searchRecd(Date & date1, Date & date2)
{
	if (date1 > date2)
	{
		printf("date is invalid\n");
		return;
	}
	RcdItem item1, item2;
	item1.date = date1;
	item2.date = date2;
	for (list<RcdItem>::iterator iter = record.begin();iter != record.end() && (*iter)>=item1 && (*iter)<=item2;iter++)
		PrintItem(*iter);
}
Account& DemandAcct::operator=(Account& account) throw(bad_alloc)
{
	Account::operator=(account);//deep copy,throw(bad_alloc)
	printf("= DemandAcct\n");
	return *this;
}


