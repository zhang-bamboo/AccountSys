#include"RcdItem.h"
#include<stdio.h>



void PrintItem(RcdItem& item)
{
	if (item.add)
		printf("+%d  ", item.amount);
	else
		printf("-%d  ", item.amount);
	item.date.displayDate();
	printf("\n");
}

RcdItem::RcdItem()//:add(0),amount(0),date(2016,1,1)
{
}

RcdItem::RcdItem(bool ad, int am, Date dat) throw()
{
	add = ad;
	amount = am;
	date = dat;
}

RcdItem::~RcdItem()
{
}

bool RcdItem::operator<=(RcdItem &anotherItem)
{
	if (date <= anotherItem.date)
		return true;
	return false;
}

bool RcdItem::operator>=(RcdItem &anotherItem)
{
	if (date >= anotherItem.date)
		return true;
	return false;
}

bool RcdItem::operator<(RcdItem &anotherItem) throw()
{
	if (date < anotherItem.date)
		return true;
	return false;
}

bool RcdItem::operator>(RcdItem &anotherItem) throw()
{
	if (date > anotherItem.date)
		return true;
	return false;
}
