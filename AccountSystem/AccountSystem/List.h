#ifndef _LIST_H_
#define _LIST_H_
#include<stdio.h>
#include<stdexcept>
#include<new>

template<typename ItemType>
class List
{
public:
	struct Node
	{
		ItemType item;
		Node *next;
	};
public:
	List() throw();
	~List() throw();
	bool ListIsEmpty() const throw();
	bool ListIsFull() const throw();
	int ListItemCount() const throw();
	bool ListAddItem(ItemType& item) throw(std::bad_alloc);
	void TraverseList(void(*p_func)(ItemType&)) throw();
	void TravSomeItem(ItemType& item1,ItemType& item2,void(*p_func)(ItemType&)) throw();
	void ProcessNode(int nodenum, void(*p_func)(ItemType&)) throw(std::invalid_argument);
	bool DeleteItem(int nodenum) throw(std::invalid_argument);
	bool InsertItem(ItemType& item, int nodenum) throw(std::invalid_argument, std::bad_alloc);
	bool ReplaceItem(ItemType& item, int nodenum) throw(std::invalid_argument);
	bool GetnItem(ItemType& item, int nodenum) throw(std::invalid_argument);
	List<ItemType>& operator=(List<ItemType>&) throw(std::bad_alloc);
protected:
	Node** SeekCount(int nodenum)//在cpp中定义，Node** 不可见成员类型
	{
		int i;
		Node *pnode;
		if (nodeCount == 0 || nodenum <= 0 || nodenum>nodeCount + 1)
			return NULL;
		if (nodenum == 1)
			return(&head);
		for (i = 2, pnode = head;i<nodenum;i++, pnode = pnode->next);
		return(&(pnode->next));
	}
protected:
	Node *head=NULL;
	int nodeCount=0;
};

#include"List.cpp"

#endif
