

template<typename ItemType>
List<ItemType>::List()
{
	printf("constructing list\n");
}
template<typename ItemType>
List<ItemType>::~List()
{
	Node *pnode;
	while (head != NULL)
	{
		pnode = head->next;
		delete head;
		head = pnode;
	}
	printf("Destructing List\n");
	nodeCount = 0;
}
template<typename ItemType>
bool List<ItemType>::ListIsEmpty() const
{
	if (head == NULL)
		return(true);
	return(false);
}
template<typename ItemType>
bool List<ItemType>::ListIsFull() const
{
	Node *pnode;
	if ((pnode = new Node) == NULL)
		return(true);
	delete pnode;
	return(false);
}
template<typename ItemType>
int List<ItemType>::ListItemCount() const
{
	return(nodeCount);
}
template<typename ItemType>
bool List<ItemType>::ListAddItem(ItemType& item) throw(std::bad_alloc)
{
	Node *pnew, *pnode;
	if ((pnew = new Node) == NULL)
		throw bad_alloc();
	pnew->item = item;
	pnew->next = NULL;
	if (ListIsEmpty())
		head = pnew;
	else
	{
		for (pnode =head;pnode->next != NULL;pnode = pnode->next);
		pnode->next = pnew;
	}
	nodeCount++;
	return(true);
}
template<typename ItemType>
void List<ItemType>::TraverseList(void(*p_func)(ItemType&))
{
	Node *pnode;
	if (head == NULL)
	{
		printf("empty list\n");
		return;
	}
	for (pnode = head;pnode != NULL;pnode = pnode->next)
		(*p_func)(pnode->item);
}
template<typename ItemType>
void List<ItemType>::TravSomeItem(ItemType &item1,ItemType &item2, void(*p_func)(ItemType&))
{
	Node *pnode;
	if (head == NULL||item1<item2)
		return;
	for (pnode = head;pnode != NULL;pnode = pnode->next)
		if(pnode->item>=item1&&pnode->item<=item2)
			(*p_func)(pnode->item);
}
template<typename ItemType>
void List<ItemType>::ProcessNode(int  nodenum, void(*p_func)(ItemType&)) throw(std::invalid_argument)
{
	Node **ppnode;
	if (nodenum > nodeCount || (ppnode = SeekCount(nodenum)) == NULL)
		throw std::invalid_argument("invalid argument for List<ItemType>::ProcessNode");
	(*p_func)((*ppnode)->item);
}
template<typename ItemType>
bool List<ItemType>::DeleteItem(int nodenum) throw(std::invalid_argument)
{
	Node **ppnode;
	if (nodenum>nodeCount || (ppnode = SeekCount(nodenum)) == NULL)
		throw std::invalid_argument("invalid argument for List<ItemType>::DeleteItem");
	Node *pnode = (*ppnode);
	(*ppnode) = (*ppnode)->next;
	delete pnode;
	nodeCount--;
	return true;
}
template<typename ItemType>
bool List<ItemType>::InsertItem(ItemType& item, int nodenum) throw(std::invalid_argument, std::bad_alloc)
{
	Node **ppnode;
	if ((ppnode = SeekCount(nodenum)) == NULL)
		throw std::invalid_argument("invalid argument for List<ItemType>::InsertItem");
	Node *pnewnode;
	if ((pnewnode = new Node) == NULL)
		throw std::bad_alloc();
	pnewnode->item = item;
	pnewnode->next=(*ppnode);
	(*ppnode) = pnewnode;
	nodeCount++;
	return true;
}
template<typename ItemType>
bool List<ItemType>::ReplaceItem(ItemType& item, int nodenum) throw(std::invalid_argument)
{
	Node **ppnode;
	if (nodenum>nodeCount || (ppnode = SeekCount(nodenum)) == NULL)
		throw std::invalid_argument("invalid argument for List<ItemType>::ReplaceItem");
	(*ppnode)->item = item;
	return(true);
}
template<typename ItemType>
bool List<ItemType>::GetnItem(ItemType& item, int nodenum) throw(std::invalid_argument)
{
	Node **ppnode;
	if (nodenum>nodeCount || (ppnode = SeekCount(nodenum)) == NULL)
		throw std::invalid_argument("invalid argument for List<ItemType>::ReplaceItem");
	item =((*ppnode)->item);
	return(true);
}
template<typename ItemType>
List<ItemType>& List<ItemType>::operator=(List<ItemType>& anList) throw(std::bad_alloc)
{
	ItemType item;
	this->~List();
	for (int i = 1;i <= anList.nodeCount;i++)
	{
		anList.GetnItem(item, i);
		ListAddItem(item);//throw(std::bad_alloc)
	}
	return *this;
}

//template<typename ItemType>
//List<ItemType>::Node ** List<ItemType>::SeekCount(int nodenum)
//{
//	return nullptr;
//}

