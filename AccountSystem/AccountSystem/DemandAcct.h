#ifndef _DEMAND_ACCOUNT_H_
#define _DEMAND_ACCOUNT_H_
#include<string>
#include"Account.h"
#include"RcdItem.h"
#include"DateClass.h"
using namespace std;

class DemandAcct:public Account
{
public:
	DemandAcct(string accountName,int accountBalance,Date& date) throw();
	DemandAcct(DemandAcct& account) throw(bad_alloc);
	DemandAcct() throw();
	~DemandAcct() throw();
	int getBalance() throw();
	void deposite(int amount,Date& date) throw(bad_alloc, invalid_argument);
	void withdraw(int amount,Date& date) throw(bad_alloc, invalid_argument);
	void printAllRecd() throw();//print all record
	void searchRecd(Date& date1,Date& date2) throw(bad_alloc, invalid_argument); 
	//only print all record between date1 and date2
	Account& operator=(Account& account) throw(bad_alloc);
	//deep copy,if bad_alloc ~List();
};





#endif
