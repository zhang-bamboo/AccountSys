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

int Account::getPassword() const
{
	return password;
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

int Account::getNums()
{
	return allAccounts;
}
