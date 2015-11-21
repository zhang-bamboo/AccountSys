#ifndef _RCD_LIST_H
#define _RCD_LIST_H
#include<stdexcept>
#include"DateClass.h"

struct RcdItem
{
public:
	RcdItem() throw();
	RcdItem(bool ad,int am,Date dat) throw();
	~RcdItem() throw();
	bool operator<=(RcdItem&) throw();
	bool operator>=(RcdItem&) throw();
	bool operator<(RcdItem&) throw();
	bool operator>(RcdItem&) throw();
	bool add=0;
	int amount=0;
	Date date;
};

extern void PrintItem(RcdItem& item);


#endif

