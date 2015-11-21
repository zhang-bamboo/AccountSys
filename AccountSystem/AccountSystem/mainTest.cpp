#include<stdio.h>
#include<iostream>
#include<string>
#include<stdexcept>
#include<new>
#include<list>
#include"autoPtr.h"
#include"DemandAcct.h"
#include"CreditCardAcct.h"
#include"DateClass.h"
//using namespace std;


int InputNum()
{
	int num;
	printf("num= ");
	scanf_s("%d", &num);
	return(num);
}
//num begin from 0
list<AutoPtr<Account>>::iterator seekList(int curId,list<AutoPtr<Account>>& accList)
{
	list<AutoPtr<Account>>::iterator iter;
	if (curId > Account::getNums() || curId < 0 || accList.empty())
	{
		return accList.end();
	}
	for (iter = accList.begin();iter!=accList.end()&&((*iter)->getNumber())!=curId;iter++);
	return iter;
}

int main(int argc, char *argv[])
{
	char ch;
	int num;
	int curId=0;
	int i;
	list<AutoPtr<Account>>::iterator iter;	
	AutoPtr<Account> ptacct;
	string account_name = "zhang";
	Date date1;
	Date date2;
	try{
		date1.setDate(2015, 10, 10);	
		date2.setDate(2015, 10, 10);
	}
	catch(invalid_argument e){
		cout << e.what() << endl;
	}
	list<AutoPtr<Account>> accList;
	printf("Press following button\n"
		"c: to change password  n: to get account_name\n"
		"b: to get account_id  l: to get account_balance\n"
		"d: to deposite  w: to withdraw\n"
		"s: to search  p: to print all item\n"
		"a:to add account i:to set current account_id\n"
		"q to quit\n");
	while (1)
	{
		while ((ch = getchar()) == '\n');
		while (getchar() != '\n');
		if (ch == 'q')
			break;
		switch (ch)
		{
		case 'a':
			cout << "DemandAcct:0  CreditCardAcct:1" << endl;
			cin >> num;
			cout << "account name=";
			cin >> account_name;
			if (num == 0)
			{
				AutoPtr<Account> pAcct(new DemandAcct(account_name, 0, date1));
				ptacct = pAcct;
				pAcct.release();
			}
			else if (num == 1)
			{
				AutoPtr<Account> pAcct(new CreditCardAcct(account_name, 0, date1));
				ptacct = pAcct;
				pAcct.release();
			}
			else
				break;
			if (ptacct.get()!=NULL)
			{
				accList.push_back(ptacct);
				ptacct.release();
				printf("Add account successfully\n");
			}
			break;
		case 'i':
			cout << "account_id=";
			cin >> curId;
			break;
		case 'c':
			if ((iter = seekList(curId, accList)) != accList.end())
			{
				cout << "new password=";
				cin >> num;
				(*iter)->chgPassword(num);
				printf("change password successfully\n");
			}
			else
				cout << "invalid input" << endl;
			break;
		case 'n':
			if ((iter = seekList(curId, accList)) != accList.end())
			{
				cout << (*iter)->getName() << endl;
			}
			else
				cout << "invalid input" << endl;
			break;
		case 'b':
			if ((iter = seekList(curId, accList)) != accList.end())
			{
				cout << (*iter)->getNumber() << endl;
			}
			else
				cout << "invalid input" << endl;
			break;
		case 'l':
			if ((iter = seekList(curId, accList)) != accList.end())
			{
				cout << (*iter)->getBalance() << endl;
			}
			else
				cout << "invalid input" << endl;
			break;
		case 'd':
			if ((iter = seekList(curId, accList)) != accList.end())
			{
				printf("deposite num=");
				scanf_s("%d", &num);
				(*iter)->deposite(num, date1);
			}
			else
				cout << "invalid input" << endl;
			break;
		case 'w':
			if ((iter = seekList(curId, accList)) != accList.end())
			{
				printf("withdraw num=");
				scanf_s("%d", &num);
				(*iter)->withdraw(num, date1);
			}
			else
				cout << "invalid input" << endl;		
			break;
		case 'p':
			if ((iter = seekList(curId, accList)) != accList.end())
				(*iter)->printAllRecd();
			else
				cout << "invalid input" << endl;
			break;
		case 's':
			if ((iter = seekList(curId, accList)) != accList.end())
				(*iter)->searchRecd(date1, date2);
			else
				cout << "invalid input" << endl;
			break;
		case 'z':
				printf("delete num=");
				scanf_s("%d", &num);
				if ((iter = seekList(num, accList)) != accList.end())
					accList.erase(iter);
			else
				cout << "invalid input" << endl;
			break;
		default:
			printf("press again\n");
			break;
		}
	}
	printf("Bye\n");
	return 0;
}
