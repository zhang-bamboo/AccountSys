#ifndef _ACCOUNT_LIST_H
#define _ACCOUNT_LIST_H
#include<stdexcept>
#include<new>
#include"account.h"
#include"List.h"


class AccountList:public List<Account*>
{
public:
	AccountList() throw();
	~AccountList() throw();
	//void TraverseList(void(*p_func)(Account& item)) throw();
	void PrintList() throw();
	void PrintSomeItem(Account& item1,Account& item2) throw();
	void PrintnItem(int nodenum) throw(std::invalid_argument);
	bool DeleteItem(int nodenum) throw(std::invalid_argument);
	bool InsertItem(Account* ptr_item, int nodenum) throw(std::invalid_argument, std::bad_alloc);
	bool ReplaceItem(Account* ptr_item, int nodenum) throw(std::invalid_argument);
	AccountList& operator=(AccountList&) throw(std::bad_alloc);
	//小心指针别名
};

#endif
