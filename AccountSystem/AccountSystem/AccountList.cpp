#include"AccountList.h"
#include<stdio.h>

static void del_pitem(Account *& pitem)
{
	if (pitem != NULL)
		delete pitem;
}
//empty function
static void PrintItem(Account*& item)
{
	printf("PrintItem() is empty\n");
	printf("\n");
}

AccountList::AccountList()
{

}

AccountList::~AccountList()
{
	List<Account*>::TraverseList(del_pitem);
	List<Account*>::~List();
}

//void AccountList::TraverseList(void(*p_func)(Account& item))
//{
//	Node *pnode;
//	if (head==(Node*)NULL)
//	{
//		fprintf(stderr, "empty list\n");
//		return;
//	}
//	for (pnode = head;pnode != NULL;pnode = pnode->next)
//		(*p_func)(*(pnode->item));
//}


void AccountList::PrintList()
{
	List<Account*>::TraverseList(PrintItem);
}
//bug
void AccountList::PrintSomeItem(Account& item1,Account& item2)
{
	Account *pitem1=&item1, *pitem2=&item2;
	List<Account*>::TravSomeItem(pitem1, pitem2, PrintItem);
}

void AccountList::PrintnItem(int nodenum)
{
	Account *pitem;
	List<Account*>::GetnItem(pitem, nodenum);
	PrintItem(pitem);
}

bool AccountList::DeleteItem(int nodenum) throw(std::invalid_argument)
{
	Node **ppnode;
	if (nodenum>nodeCount || (ppnode = List<Account*>::SeekCount(nodenum)) == NULL)
		throw std::invalid_argument("invalid argument for List<ItemType>::DeleteItem");
	delete ((*ppnode)->item);
	if(List<Account*>::DeleteItem(nodenum))
		return true;
	return false;
}

bool AccountList::InsertItem(Account* ptr_item, int nodenum) throw(std::invalid_argument, std::bad_alloc)
{
	if (List<Account*>::InsertItem(ptr_item, nodenum))
		return true;
}

bool AccountList::ReplaceItem(Account* ptr_item, int nodenum) throw(std::invalid_argument)
{
	Node **ppnode;
	if (nodenum>nodeCount || (ppnode = SeekCount(nodenum)) == NULL)
		throw std::invalid_argument("invalid argument for List<ItemType>::DeleteItem");
	if ((*ppnode)->item != NULL)
		delete (*ppnode)->item;
	((*ppnode)->item) = ptr_item;
	return true;
}

AccountList & AccountList::operator=(AccountList & anList)
{
	Account* item;
	this->~AccountList();
	for (int i = 1;i <= anList.nodeCount;i++)
	{
		anList.GetnItem(item, i);
		ListAddItem(item);
	}
	return *this;
}

