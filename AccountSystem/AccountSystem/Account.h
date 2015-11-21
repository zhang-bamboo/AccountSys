#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include<string>
#include<list>
#include"RcdItem.h"
#include"DateClass.h"
using namespace std;

class Account
{
public:	
	Account() throw();
	virtual ~Account() throw();
	bool cmpPassword(int psword) const throw();
	void chgPassword(int psword) throw();
	list<RcdItem>& getRecord() throw();
	int getNumber() const throw();
	string getName() const throw();
	virtual int getBalance()=0;
	virtual void deposite(int amount, Date& date)=0;
	virtual void withdraw(int amount, Date& date)=0;
	virtual void printAllRecd()=0;//print all record
	virtual void searchRecd(Date& date1, Date& date2)=0;
	virtual Account& operator=(Account& account)throw(bad_alloc);
	static int getNums();
protected:	
	static int allAccounts;
	int password;
	int account_id;
	string account_name;
	int account_balance;
	list<RcdItem> record;
};



#endif // !_ACCOUNT_H_

