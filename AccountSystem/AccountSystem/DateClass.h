#ifndef _DATECLASS_H_
#define _DATECLASS_H_
#include<stdexcept>
#include<new>
class Date
{
public:
	Date(int y,int m,int d) throw(std::invalid_argument);
	Date() throw();
	~Date() throw();
	void setDate(int y,int m,int d) throw(std::invalid_argument);
	int getYear() const throw();
	int getMonth() const throw();
	int getDay() const throw();
	void incrementDate() throw();
	void decrementDate() throw();
	void showWeek() throw();
	int toWeek() const throw();
	void displayDate() const throw();
	bool operator ==(Date& anotherDate) throw();
	bool operator >(Date& anotherDate) throw();
	bool operator >=(Date& anotherDate) throw();
	bool operator <(Date& anotherDate) throw();
	bool operator <=(Date& anotherDate) throw();
private:
	int year=2015;
	int month=10;
	int day=1;
};







#endif




