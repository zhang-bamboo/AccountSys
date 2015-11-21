#ifndef _CREDIT_CARD_ACCOUNT_H_
#define _CREDIT_CARD_ACCOUNT_H_
#include<string>
#include"Account.h"
#include"DateClass.h"
#include<stdexcept>
using namespace std;

class CreditCardAcct :public Account
{
public:
	CreditCardAcct(string accountName, int accountBalance, Date& date) throw();
	CreditCardAcct(CreditCardAcct& account) throw(bad_alloc);
	CreditCardAcct() throw();
	~CreditCardAcct() throw();
	int getBalance() throw();
	void deposite(int amount, Date& date) throw(bad_alloc, invalid_argument);
	void withdraw(int amount, Date& date) throw(bad_alloc, invalid_argument);
	void printAllRecd() throw();//print all record
	void searchRecd(Date& date1, Date& date2) throw(invalid_argument);
	//only print all record between date1 and date2
	Account& operator=(Account& account) throw(bad_alloc);//deep copy
private:
	int creditLimit;
};


#endif