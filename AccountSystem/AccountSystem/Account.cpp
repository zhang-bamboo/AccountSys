#include "Account.h"


int Account::allAccounts = 0;

Account::Account()
{
	printf("Contructing Account\n");
}

Account::~Account()
{
	printf("Destructing Account\n");
}


bool Account::cmpPassword(int psword) const
{
	if (password == psword)
		return true;
	return false;
}

void Account::chgPassword(int psword)
{
	password = psword;
}

list<RcdItem>& Account::getRecord()
{
	return record;
}

int Account::getNumber() const
{
	return account_id;
}

string Account::getName() const
{
	return account_name;
}

//Account & Account::operator=(Account & account)
//{
	
//}

Account& Account::operator=(Account & account)throw(bad_alloc)
{
	record = account.record;//deep copy,throw(bad_alloc)
	password = account.password;
	account_id = account.account_id;
	account_name = account.account_name;
	account_balance = account.account_balance;
	return *this;
}

int Account::getNums()
{
	return allAccounts;
}
